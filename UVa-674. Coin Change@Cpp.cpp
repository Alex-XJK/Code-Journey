#include <iostream>
using namespace std;

//Jiakai XU, June 21 2021, coding for OJ 217Coin Change

#define maxlen 7500

int coin[5] = { 1,5,10,25,50 };
long memr[maxlen][5];

long coinc(int, short);

int main() {
	int input = -1;
	int threshold = 1500;
	while (cin >> input) {
		if (input < 0) {
			break;
		}
		if (input >= 4 * threshold) { //Prevent stack overflow 4x
			coinc(2 * threshold, 4);
			coinc(4 * threshold, 4);
			threshold = input;
		}
		else if (input >= 2 * threshold) { //Prevent stack overflow 2x
			coinc(2 * threshold, 4);
			threshold = input;
		}
		cout << coinc(input, 4) << endl;
	}
	return 0;
}

long coinc(int num, short coi = 4) {
	if (num == 0) {
		return 1;
	}
	else {
		long ans = 0;
		long tmp = 0;
		for (int i = 0; i <= coi; i++) {
			if (num >= coin[i]) {
				tmp = memr[num - coin[i]][i];
				if (tmp <= 0) {
					tmp = coinc(num - coin[i], i);
				}
				ans += tmp;
			}
			memr[num][i] = ans;
		}
		return ans;
	}
}
