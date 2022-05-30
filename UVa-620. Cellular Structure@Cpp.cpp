#include <iostream>
#include <cstring>
using namespace std;

//Jiakai XU, June 17 2021, coding for OJ 195Cellular Structure

#define maxlength 1001 //Max word length that can be input, not sure in this question

int checkstruc(char* str, int start, int end);

int main() {
	int testcase = 0;
	cin >> testcase;
	int len = 0;
	int result = 0;
	char str[maxlength];
	for (int tc = testcase - 1; tc >= 0; tc--) {
		// Get user input and compute the string length
		cin >> str;
		len = strlen(str);
		// Primary checking the length to save time
		if (len % 2 == 0) { //Notice that if we add any 2 chars to an existig O, 1+2=3, 3+2=5, 7, 9, the total length shold be ODD not EVEN.
			result = -1;
		}
		else {
			result = checkstruc(str, 0, len - 1);
		}
		// Judge and output the result
		switch (result) {
		case 1:
			cout << "SIMPLE" << endl;
			break;
		case 2:
			cout << "FULLY-GROWN" << endl;
			break;
		case 3:
			cout << "MUTAGENIC" << endl;
			break;
		default:
			cout << "MUTANT" << endl;
			break;
		}
		// Clear up for next run
		result = 0;
		len = 0;
	}
	return 0;
}

/**
* Read the structure and check the site, using recursion.
* @param str	The whole structure of target
* @param start	The starting point of checking
* @param end	The ending point of checking
* @return	0	Initial value or end point;
*			1	Only one character of A;
*			2	Ending two characters are A and B, _ _ _ A B;
*			3	Staring with B, and ending with A, B _ _ _ A;
*			-1	Illegal or other unknown structure.
*/
int checkstruc(char* str, int start, int end) {
	if (start > end) {
		return 0;
	}
	else if (str[start] == 'A' && start == end) { // A
		return 1;
	}
	else if (str[end - 1] == 'A' && str[end] == 'B') { // xxxAB
		if (checkstruc(str, start, end - 2) < 0) {
			return -1;
		}
		else {
			return 2;
		}
	}
	else if (str[start] == 'B' && str[end] == 'A') { // BxxxA
		if (checkstruc(str, start + 1, end - 1) < 0) {
			return -1;
		}
		else { 
			return 3;
		}
	}
	else {
		return -1;
	}
}