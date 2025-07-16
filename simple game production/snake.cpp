#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <windows.h>
#include <conio.h>

// --- 遊戲設定 ---
const int width = 40;
const int height = 20;
const int MAX_LENGTH = 20; // 蛇的最大長度

// --- 速度設定 ---
const long long INITIAL_DELAY_MS = 250; // 初始延遲時間 (毫秒)，數字越大速度越慢
const long long MIN_DELAY_MS = 60;      // 最快速度的延遲時間 (毫秒)，數字越小速度越快
const long long SPEED_INCREMENT = 10;   // 每吃到一顆蘋果，延遲減少的時間 (毫秒)

// --- 遊戲狀態變數 ---
bool gameOver;
int totalApplesEaten; // 總共吃掉的蘋果數，作為分數
long long current_delay_ms; // 當前的遊戲延遲時間

// --- 座標結構 ---
struct Point {
    int x, y;
};

Point head, apple;
std::vector<Point> snakeBody;

// --- 方向枚舉 ---
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// 設定隨機數產生器
std::random_device rd;
std::mt19937 generator(rd());

// 隱藏主控台的游標
void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

// 產生新蘋果
void GenerateApple() {
    std::uniform_int_distribution<int> width_dist(1, width - 2);
    std::uniform_int_distribution<int> height_dist(1, height - 2);
    
    // 確保蘋果不會產生在蛇的身體上
    bool on_snake;
    do {
        on_snake = false;
        apple.x = width_dist(generator);
        apple.y = height_dist(generator);
        if (apple.x == head.x && apple.y == head.y) {
            on_snake = true;
            continue;
        }
        for (const auto& part : snakeBody) {
            if (part.x == apple.x && part.y == apple.y) {
                on_snake = true;
                break;
            }
        }
    } while (on_snake);
}

// 遊戲初始化
void Setup() {
    gameOver = false;
    dir = STOP;
    totalApplesEaten = 0;
    current_delay_ms = INITIAL_DELAY_MS;
    HideCursor();

    head.x = width / 2;
    head.y = height / 2;
    snakeBody.clear();

    GenerateApple();
}

// 繪製遊戲畫面
void Draw() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

    // --- 繪製包含分數的頂部牆壁 ---
    std::string score_text = " Score: " + std::to_string(totalApplesEaten) + " ";
    std::cout << "#"; // 左上角
    std::cout << score_text;
    for (int i = 0; i < width - 2 - score_text.length(); ++i) {
        std::cout << "#";
    }
    std::cout << "#" << std::endl;

    // 繪製地圖中間部分
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == 0 || x == width - 1) {
                std::cout << "#";
            } else if (y == head.y && x == head.x) {
                std::cout << "O";
            } else if (y == apple.y && x == apple.x) {
                std::cout << "A";
            } else {
                bool isBodyPart = false;
                for (const auto& part : snakeBody) {
                    if (part.x == x && part.y == y) {
                        std::cout << "o";
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    // 繪製底部牆壁
    for (int i = 0; i < width; ++i) std::cout << "#";
    std::cout << std::endl;
}

// 處理鍵盤輸入
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': if (dir != RIGHT) dir = LEFT; break;
        case 'd': if (dir != LEFT) dir = RIGHT; break;
        case 'w': if (dir != DOWN) dir = UP; break;
        case 's': if (dir != UP) dir = DOWN; break;
        case 'x': gameOver = true; break;
        }
    }
}

// 遊戲邏輯更新
void Logic() {
    Point prev_head_pos = head;
    if (!snakeBody.empty()) {
        snakeBody.insert(snakeBody.begin(), prev_head_pos);
        snakeBody.pop_back();
    }

    switch (dir) {
    case LEFT:  head.x--; break;
    case RIGHT: head.x++; break;
    case UP:    head.y--; break;
    case DOWN:  head.y++; break;
    }

    if (head.x >= width - 1 || head.x <= 0 || head.y >= height || head.y < 0) {
        gameOver = true;
    }
    for (const auto& part : snakeBody) {
        if (part.x == head.x && part.y == head.y) {
            gameOver = true;
            break;
        }
    }

    if (head.x == apple.x && head.y == apple.y) {
        totalApplesEaten++;

        // 速度提升 (減少延遲時間)
        if (current_delay_ms > MIN_DELAY_MS) {
            current_delay_ms -= SPEED_INCREMENT;
        }
        
        // 身體變長
        snakeBody.insert(snakeBody.begin(), prev_head_pos);

        // 檢查是否達到最大長度
        if (snakeBody.size() + 1 >= MAX_LENGTH) {
            snakeBody.clear(); // 長度重置
        }

        // 產生新蘋果
        GenerateApple();
    }
}

// --- 主程式 ---
int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(current_delay_ms));
    }
    std::cout << "Game Over! Final Score: " << totalApplesEaten << std::endl;
    system("pause"); // 等待使用者按鍵後再關閉視窗
    return 0;
}