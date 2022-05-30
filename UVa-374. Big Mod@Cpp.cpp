#include <iostream>
using namespace std;

#pragma GCC optimize(2)
//#pragma warning(disable : 4996)

//Jiakai XU, October 5 2021, coding for OJ 212 Big Mod (UVA374)

/**
 * Core calculation of "(a * b) % c = [(a % c) * (b % c)] % c".
 */
inline int core(int a, int b, int c) {
	return (((a % c) * (b % c)) % c);
}

/**
 * To judge whether a number n is Odd or not.
 */
inline bool isOdd(int n) {
	return (n % 2 != 0);
}

/**
 * Calculate the quick power result of given <B, P, M>.
 * @param base		the base number from 0 to INT_MAX
 * @param power		the power number from 0 to INT_MAX
 * @param modulus	the modulus value from 0 to 46340
 * @return the calculation result
 */
int quickPower(int base, int power, int modulus) {
	if (power == 0) {
		return (1 % modulus);
	}
	else if (isOdd(power)) {
		int tmp = quickPower(base, power - 1, modulus);
		return core(base, tmp, modulus);
	}
	else {
		int tmp = quickPower(base, power / 2, modulus);
		return core(tmp, tmp, modulus);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	int B, P, M;
	while (cin >> B >> P >> M) {
		cout << quickPower(B, P, M) << endl;
	}
	
	return 0;
}