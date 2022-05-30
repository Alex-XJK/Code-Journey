#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//Jiakai XU, July 21 2021, coding for OJ 314Extend to Palindromes
//After getting Time Limit Exceeded for so many times, I am here try to use a new method on my previous new method

class KMP_modified
{
public:
	KMP_modified(string pattern) {
		patternstr = pattern;
		const int length = pattern.size();
		dfa = new int[length + 1];
	}
	void buildNext() {
		dfa[0] = -1;
		int i = 0, j = -1;
		while (patternstr[i]) {
			if (j == -1 || patternstr[i] == patternstr[j]) {
				++i; ++j;
				if (patternstr[i] != patternstr[j])
					dfa[i] = j;
				else dfa[i] = dfa[j];
			}
			else j = dfa[j];
		}
	}
	int searchMatch(string text) {
		const int len = text.size();
		int j = 0;
		for (int i = 0; i < len;) {
			if (j == -1 || text[i] == patternstr[j]) {
				i++;
				j++;
			}
			else {
				j = dfa[j];
			}
		}
		return j;
	}
	~KMP_modified() {
		delete[] dfa;
	}
private:
	string patternstr;
	int* dfa;
};

string str;
string rev_str;

int main() {
	while (cin >> str) {
		//Create reversed string as pattern
		rev_str = str;
		reverse(rev_str.begin(), rev_str.end());

		//KMP method group
		KMP_modified kmp(rev_str);
		kmp.buildNext();
		const int returnPoint = kmp.searchMatch(str);

		//Final print out
		cout << str << &rev_str[returnPoint] << endl;
	}
	return 0;
}