#include <iostream>
#include <iomanip>
using namespace std;

//Jiakai XU, June 13 2021, coding for OJ 278Above Average
//ver1: Get several Compilation Error before AC, problems seems to be related with <stdio.h> and scanf (scanf_s) 

int main() {
	int testcase = 0, people = 0, temp = 0, count = 0, res = 0;
	float sum = 0, average = 0;	
	int* grade = NULL;

	cin >> testcase;
	for (int tc = testcase - 1; tc >= 0; tc--) {
		cin >> people;
		grade = new int[people];
		for (int idx = 0; idx < people; idx++) {
			cin >> temp;
			grade[idx] = temp;
			sum += temp;
		}
		average = sum / people;
		for (int i = people - 1; i >= 0; i--) {
			if (grade[i] > average) {
				count += 1;
			}
		}
		cout << fixed;
		cout << setprecision(3);
		cout << ((float)count / people) * 100 << "%" << endl;

		//Clean up
		sum = 0;
		count = 0;
		delete[] grade;
	}
	return 0;
}