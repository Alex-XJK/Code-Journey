#include <iostream>
using namespace std;

//Jiakai XU, June 13 2021, coding for OJ 192Not so Mobile
//ver1-4 : submission id 163675, 163676, 163680, 163687 Wrong Answer
//		The early "-1" detection of w1 and w2 recursion result, will result Input Error, 
//		that is to leave the input buffer unread and start to judge next testcase.
//ver5 : submission id 163712 Presentation Error
//		The last time to output, not satisfy "two consecutive cases" requirement, no need extra empty line.


/**
* Read in the user input and make judgement recursively.
* @return	-1	if not balanced
*			>0	the total weight of its sub-tree 
* @version	2.0
*/
int ReadAndJudge() {
	int w1 = 0, d1 = 0, w2 = 0, d2 = 0;
	cin >> w1 >> d1 >> w2 >> d2;

	if (w1 == 0) {
		w1 = ReadAndJudge();
	}
	if (w2 == 0) {
		w2 = ReadAndJudge();
	}

	if (w1 == -1 || w2 == -1) {
		return -1;
	}

	int left = w1 * d1;
	int right = w2 * d2;
	if (left == right) {
		//// -->
		//cout << "Balanced with return-value " << w1 + w2 << endl;
		//// <--
		return w1 + w2;
	}
	else {
		//// -->
		//cout << "Not balanced!" << endl;
		//// <--
		return -1;
	}
}

int main() {
	int testcase = 0;
	cin >> testcase;
	for (int tc = testcase - 1; tc >= 1; tc--) {
		if (ReadAndJudge() > 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		cout << endl;
	}
	//Last output
	if (ReadAndJudge() > 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}