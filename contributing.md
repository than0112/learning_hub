# 貢獻指南 (Contribution Guidelines) 🎉

你好！非常感謝你對這個 C++ 學習專案感興趣，並願意花費時間讓它變得更好。

這個專案是我個人學習 C++ 的軌跡記錄，充滿了從基礎到進階的各種練習與小型專案。我非常歡迎任何形式的貢G獻。無論是修正一個小錯字，提供一個更佳的演算法，或是分享一個新的練習專案點子，你的每一個貢獻都非常有價值。

為了讓協作過程更加順利，請花幾分鐘閱讀以下的貢獻指南。

## 行為準則 (Code of Conduct)

為了營造一個友善、互相尊重、且有建設性的學習環境，我期望所有參與者都能遵守我的 [行為準則 (CODE_OF_CONDUCT.md)](CODE_OF_CONDUCT.md)。請在參與貢獻前閱讀它。

## 如何貢獻？

你可以透過以下幾種方式來貢獻：

### 🐛 回報 Bug
如果你發現程式碼中有任何錯誤、無法執行的情況，或與預期結果不符的地方，請不要猶豫，直接到 [Issues 頁面]([請貼上你 GitHub 專案的 Issues 頁面連結]) 建立一個新的 issue。

在回報時，請盡可能詳細地描述：
* 你使用的作業系統與編譯器版本。
* 重現這個 bug 的詳細步驟。
* 你預期的結果是什麼，以及實際發生的結果是什麼。

### ✨ 提出功能建議或新點子
如果你有任何關於新練習專案、程式碼優化、或是其他可以讓這個專案更好的想法，也歡迎到 [Issues 頁面]([請貼上你 GitHub 專案的 Issues 頁面連結]) 建立一個 issue，並使用 "enhancement" 或 "idea" 標籤。

### 🚀 提交程式碼 (Pull Requests)
如果你想直接修復 bug 或實現新功能，我非常歡迎你提交 Pull Request (PR)。請遵循以下流程。

## Pull Request 提交流程

1.  **Fork 本專案**：在你的 GitHub 帳號下建立一個本專案的複本。
2.  **Clone 你的 Fork**：將你帳號下的那個複本 clone 到你的電腦上。
3.  **建立新的分支 (Branch)**：請**務必**為你的修改建立一個新的分支。一個好的分支名稱能清楚地描述你的修改目的。
    ```bash
    # 修復 bug 的分支
    git checkout -b fix/bug-description
    
    # 新增功能的分支
    git checkout -b feature/new-cool-project
    ```
4.  **進行修改**：在你建立的新分支上，完成你的程式碼修改。請確保你的程式碼風格與本專案的風格一致。
5.  **提交變更 (Commit)**：使用清晰且符合規範的訊息來提交你的變更。
    ```bash
    git add .
    git commit -m "fix: Correct the logic in the leap year check"
    ```
6.  **推送到你的 Fork**：將你的新分支推送到你 GitHub 上的複本倉庫。
    ```bash
    git push origin fix/bug-description
    ```
7.  **建立 Pull Request**：回到原始專案的 GitHub 頁面，提交一個 Pull Request，並在說明中詳細描述你做了哪些修改以及為什麼。

## 風格指南 (Style Guides)

### Git Commit 訊息
為了讓提交歷史清晰可讀，請盡量遵循 [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) 的格式。最常用的前綴有：
* `feat:`：新增一個功能或新的練習專案。
* `fix:`：修正一個 bug。
* `docs:`：只修改了文件（例如 `README.md` 或註解）。
* `style:`：不影響程式碼邏輯的格式修改（例如排版）。
* `refactor:`：程式碼重構，既非新增功能也非修正 bug。

### C++ 程式碼風格
* **命名**: 變數和函式請使用 `snake_case` (蛇式命名法)，例如 `sum_of_digits`。類別 (Class/Struct) 請使用 `PascalCase` (帕斯卡命名法)，例如 `GameManager`。
* **排版**: 請使用 4 個空格進行縮排。
* **註解**: 對於較複雜的邏輯，請加上清晰的註解。

再次感謝你的貢獻！讓我們一起學習，一起成長。