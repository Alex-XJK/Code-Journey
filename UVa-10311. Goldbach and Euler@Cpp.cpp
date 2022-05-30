#include <iostream>
using namespace std;

#pragma GCC optimize(2)
//#pragma warning(disable : 4996)

//Jiakai XU, August 7 2021, coding for OJ 462Goldbachand Euler
//AC on UVA online judge within 1.920sec, but TLE on our oj2...
//Some system settings are changed to speed up the process

class MillerRabin
{
public:
    static bool MR(int n) {
        if (n <= 1) {
            return false;
        }
        else {
            for (int i = 0; i < size; i++) {
                if (n == prime[i]) {
                    return true;
                }
                else if (n % prime[i] == 0) {
                    return false;
                }
                else if (!MR2(n, prime[i])) {
                    return false;
                }
            }
            return true;
        }
    }
private:
    static const int size = 5;
    static const int prime[size];
    static long long quickMul(long long a, long long b, long long c) {
        return a * b % c;
    }
    static long long quickPow(long long x, long long y, long long p) {
        long long res = 1;
        while (y) {
            if (y & 1) {
                res = quickMul(res, x, p);
            }
            x = quickMul(x, x, p);
            y >>= 1;
        }
        return res;
    }
    static bool MR2(int n, int a) {
        long long d = n - 1, r = 0;
        while (!(d & 1)) {
            d >>= 1;
            r++;
        }
        long long z = quickPow(a, d, n);
        if (z == 1) {
            return 1;
        }
        else {
            for (int i = 0; i < r; i++) {
                if (z == n - 1) {
                    return 1;
                }
                z = quickMul(z, z, n);
            }
            return 0;
        }
    }
};

const int MillerRabin::prime[] = { 2, 3, 5, 7, 11 };

inline bool isOdd(int c) {
    return c % 2 != 0;
}

inline bool isEven(int c) {
    return !isOdd(c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	//freopen("462.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	int target = 0;
	while (cin >> target) {
        bool result = false;
        int ans1 = 0;
        int ans2 = 0;
        if (target < 5) {
            result = false;
        }
        else if (isOdd(target)) {
            if (MillerRabin::MR(target - 2)) {
                result = true;
                ans1 = 2;
                ans2 = target - 2;
            }
            else {
                result = false;
            }
        }
        else {
            for (int left = (target >> 1) - 1; left >= 2; left--) {
                int right = target - left;
                if (isOdd(left) && MillerRabin::MR(left) && MillerRabin::MR(right)) {
                    result = true;
                    ans1 = left;
                    ans2 = right;
                    break;
                }
                else {
                    continue;
                }
            }
        }
        //Print out result
        if (result) {
            cout << target << " is the sum of " << ans1 << " and " << ans2 << ".\n";
        }
        else {
            cout << target << " is not the sum of two primes!\n";
        }
	}
	return 0;
}