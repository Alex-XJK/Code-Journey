#include <iostream>
#include <iomanip>
using namespace std;

#pragma GCC optimize(2)
#pragma warning(disable : 4996)

//Jiakai XU, 0ctober 13 2021, coding for OJ 287 Mirror Clock (UVa 11650)

inline int char2tens(char a, char b) {
	int result = 0;
	result += (a - '0') * 10;
	result += (b - '0') * 1;
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	int testcase = 0;
	cin >> testcase;
	char a, b, t, c, d;
	for (int tc = testcase - 1; tc >= 0; tc--) {
		// Read in
		cin >> a >> b >> t >> c >> d;
		int ori_H = char2tens(a, b);
		int ori_M = char2tens(c, d);

		// Computation
		int new_H = (ori_M == 0) ? 12 : 11;
		int new_M = (ori_M == 0) ? 0 : 60;
		new_H -= ori_H;
		new_M -= ori_M;
		if (new_H <= 0) {
			new_H += 12;
		}

		//Print out
		cout << setfill('0') << setw(2);
		cout << new_H;
		cout << ':';
		cout << setfill('0') << setw(2);
		cout << new_M << endl;
	}
	return 0;
}