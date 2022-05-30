#include <iostream>
#include <stack>
using namespace std;

#pragma GCC optimize(2)
//#pragma warning(disable : 4996)

//Jiakai XU, August 8 2021, coding for OJ 190Equation

/**
* Judge the type of character and return their precedence(if has).
* @param	c	The char to judge
* @return	2	* / ; 
*			1	+ - ; 
*			0	digit ; 
*			-1	left ( ; 
*			-2	right ) ; 
* @throws	Character Unrecognizable Exception.
*/
inline int precedence(char c) {
	if (c >= '0' && c <= '9') {
		return 0;
	}
	else if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '(') {
		return -1;
	}
	else if (c == ')') {
		return -2;
	}
	else {
		cout << "Exception: Character Unrecognizable!\n";
		return -5;
	}
}

template<class T>
T s_pop(stack<T>& s) {
	T res = s.top();
	s.pop();
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("190.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	int testcase = 0;
	char buf[4];
	cin >> testcase;
	cin.getline(buf, 2);
	cin.getline(buf, 2);
	for (int tc = testcase - 1; tc >= 0; tc--) {
		//Read in
		stack<char> op;
		while (cin.getline(buf, 2) && buf[0]) {
			char c = buf[0];
			int tap = precedence(c); //TAP: Type And Precedence
			switch (tap)
			{
			case 0: //Digit
				cout << c;
				break;
			case -1: //'('
				op.push(c);
				break;
			case -2: //')'
				while (op.top() != '(') {
					cout << s_pop(op);
				}
				op.pop();
				break;
			default: //+ - * /
				while (!op.empty() && precedence(op.top()) >= tap) {
					cout << s_pop(op);
				}
				op.push(c);
				break;
			}
		}
		//Print out remaining elements
		while (!op.empty()) {
			cout << s_pop(op);
		}
		//Print Linebreak(s)
		cout << "\n";
		if (tc) {
			cout << "\n";
		}
	}
	return 0;
}