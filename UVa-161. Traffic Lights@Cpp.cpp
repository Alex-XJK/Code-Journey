#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

#pragma GCC optimize(2)
//#pragma warning(disable : 4996)

//Jiakai XU, August 8 2021, coding for OJ 542Traffic Lights

int N = 0;
int LightCircle[104];
int second = 0;

inline bool isNowGreen(int i) {
	int curcircle = second % (2 * LightCircle[i]);
	if (curcircle < (LightCircle[i] - 5)) {
		return true;
	}
	else {
		return false;
	}
}

bool isAllGreen() {
	for (int i = 0; i < N; i++) {
		if (!isNowGreen(i)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("542.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	while (true) {
		int temp = 0;
		N = 0;
		while (cin >> temp) {
			//Current Scenario End
			if (temp == 0) {
				break;
			}
			LightCircle[N] = temp;
			N += 1;
		}
		//Trailing Zeros, Program End
		if (N == 0) {
			break;
		}
		//Find the min number
		sort(LightCircle, LightCircle + N);
		second = LightCircle[0];
		//Try one-by-one start from the min one
		bool isOk = false;
		for (second; second <= 18000; second++){
			if (isAllGreen()) {
				isOk = true;
				break;
			}
			else {
				continue;
			}
		}
		//Print out
		if (isOk) {
			int h = second / (60 * 60);
			int m = (second % (60 * 60)) / 60;
			int s = second % 60;
			cout << setfill('0');
			cout << setw(2) << h << ":";
			cout << setfill('0');
			cout << setw(2) << m << ":";
			cout << setfill('0');
			cout << setw(2) << s << "\n";
		}
		else {
			cout << "Signals fail to synchronise in 5 hours\n";
		}
	}

	return 0;
}