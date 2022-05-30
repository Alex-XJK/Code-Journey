#include <iostream>
#include <set>
#include <cmath>
using namespace std;

#pragma GCC optimize(2)
//#pragma warning(disable : 4996)

//Jiakai XU, August 7 2021, coding for OJ 361The Super Powers

//typedef unsigned long long ulong;
//CE on "onlinejudge.org", with error: conflicting declaration: /usr/include/sys/types.h:148 'typedef long unsigned int ulong'

typedef unsigned long long unslong;

bool Composite_Number[65] = {
    false, 
    false, false, false, true, false, true, false, true, true, true,
    false, true, false, true, true, true, false, true, false, true,
    true, true, false, true, true, true, true, true, false, true,
    false, true, true, true, true, true, false, true, true, true,
    false, true, false, true, true, true, false, true, true, true,
    true, true, false, true, true, true, true, true, false, true,
    false, true, true, true 
};

set<unslong> answer;
const unslong maxX = ((unslong)1 << 16);

inline unslong maxY_c(unslong x) {
    return ceil(64 * log(2) / log(x)) - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("361.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    //Compute
    for (unslong x = maxX; x >= 2; x--) {
        unslong maxY = maxY_c(x);
        unslong tart = x * x * x;
        for (unslong y = 4; y <= maxY; y++) {
            tart *= x;
            if (Composite_Number[y]) {
                answer.insert(tart);
            }
        }
    }
    answer.insert(1);

    //Print out
    set<unslong>::iterator it = answer.begin();
    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << *it << "\n";
        it++;
    }

    return 0;
}