#include <iostream>
#include <sstream>
#include <cstring>
#include <set>
using namespace std;

//#pragma warning(disable : 4996)

//Jiakai XU, August 5 2021, coding for OJ 185Andy's First Dictionary

inline bool isLowercase(char c) {
	if (c >= 97 && c <= 122) {
		return true;
	}
	else {
		return false;
	}
}

inline bool isUppercase(char c) {
	if (c >= 65 && c <= 90) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * Judge the ASCII type of a given character.
 * @param c the to be tested character
 * @return	1	Uppercase;
 *			0	Non-char;
 *			-1	Lowercase.
 */
inline int judgeChar(char c) {
	if (isUppercase(c)) {
		return 1;
	}
	else if (isLowercase(c)) {
		return -1;
	}
	else {
		return 0;
	}
}

inline char switchToLowercase(char c) {
	return (c - 'A' + 'a');
}

set<string> dictionary;

int main() {
	//freopen("185.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	string s_primary;
	string s_junior;
	//Read in data
	while (cin >> s_primary) {
		//clean out all numbers and symbols to 'space'
		const int len = s_primary.size();
		for (int idx = len - 1; idx >= 0; idx--) {
			switch (judgeChar(s_primary[idx])) 
			{
			case 1:
				s_primary[idx] = switchToLowercase(s_primary[idx]);
				break;
			case 0:
				s_primary[idx] = ' ';
				break;
			default:
				break;
			}
		}
		//get word-by-word and add to our dictionary 
		stringstream readin(s_primary);
		while (readin >> s_junior) {
			dictionary.insert(s_junior);
		}
	}
	//Print out the result
	set<string>::iterator it = dictionary.begin();
	const int length = dictionary.size();
	for (int i = 0; i < length; i++) {
		cout << *it << endl;
		it++;
	}
	return 0;
}