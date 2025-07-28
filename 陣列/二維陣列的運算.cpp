#include <iostream>
using namespace std;
int main()
{
	const int stud = 6, subject = 5;
	int score[stud][subject + 1] =
	{{34, 50, 57, 51, 65}, {44, 28, 81, 67, 74}, {66, 11, 39, 78, 67},
	 {68, 30, 10, 98, 78}, {78, 69, 70, 62, 68}, {72, 43, 49, 20, 90}};
	for (int i = 0; i < stud; i++) {
		for (int j = 0; j < subject; j++){
			cout << score[i][j] << "\t";
			score[i][subject] += score[i][j];
		}
		cout << (double)score[i][subject] / subject << endl;
	}

	return 0;
}
