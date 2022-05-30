#include <iostream>
using namespace std;

#pragma GCC optimize(2)
//#pragma warning(disable : 4996)

//Jiakai XU, August 8 2021, coding for OJ 446Economic phone calls

struct Phone
{
	int timestamp;
	bool isImportant;
	int year;
	void set (int mot, int day, int hor, int min, char c) {
		timestamp = (mot * 1000000) + (day * 10000) + (hor * 100) + (min * 1);
		if (c == '+') {
			isImportant = true;
		}
		else {
			isImportant = false;
		}
		year = 0;
	}
	void toString() {
		cout << timestamp << " ( " << year << " ) --> important: " << isImportant << endl;
	}
};

int N = 0;
Phone* record = nullptr;

inline int chars2int(char c1, char c2) {
	return (((c1 - '0') * 10) + (c2 - '0'));
}

inline bool canProceed(int i, int j) {
	bool thisyear = record[i].year == record[j].year;
	bool lastyearthistime = (record[i].timestamp >= record[j].timestamp) && (record[j].year - record[i].year == 1);
	return thisyear || lastyearthistime;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("446.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	while (cin >> N) {
		//End program
		if (N == 0) {
			break;
		}
		//Readin data
		char dig1;
		char dig2;
		char colon;
		long long pnumber;
		int month, day, hour, min;
		record = new Phone[N];
		for (int i = 0; i < N; i++) {
			cin >> dig1 >> dig2 >> colon;
			month = chars2int(dig1, dig2);
			cin >> dig1 >> dig2 >> colon;
			day = chars2int(dig1, dig2);
			cin >> dig1 >> dig2 >> colon;
			hour = chars2int(dig1, dig2);
			cin >> dig1 >> dig2;
			min = chars2int(dig1, dig2);
			cin >> pnumber;
			cin >> dig1;
			record[i].set(month, day, hour, min, dig1);
		}
		//for (int i = 0; i < N; i++) {
		//	record[i].toString();
		//}

		//Init the year
		int current_year;
		for (int i = 1; i < N; i++) {
			if (record[i].timestamp <= record[i - 1].timestamp) {
				record[i].year = record[i - 1].year + 1;
			}
			else {
				record[i].year = record[i - 1].year;
			}
		}
		current_year = record[N - 1].year;

		//Prepare the dp and look for two ends' index
		int dp[1004];
		int LastNode = -1;
		bool isFoundLast = false;
		for (int i = N - 1; i >= 0; i--) {
			if (!isFoundLast && record[i].year == current_year) {
				dp[i] = 1;
			}
			else {
				dp[i] = N;
			}

			if (!isFoundLast && (record[i].isImportant || record[i].year != current_year)) {
				LastNode = i;
				isFoundLast = true;
			}
		}

		int FirstNode = -1;
		for (int i = 0; i < N; i++) {
			if (record[i].isImportant) {
				FirstNode = i;
				break;
			}
		}

		//Compute the dp
		for (int i = LastNode; i >= FirstNode; i--) {
			for (int j = i + 1; j < N; j++) {
				if (canProceed(i,j)) {
					if (dp[i] > dp[j] + 1) {
						dp[i] = dp[j] + 1;
					}
				}
				else {
					break;
				}

				if (record[j].isImportant) {
					break;
				}
			}
		}

		//Print out
		cout << dp[FirstNode] << endl;

		//Clean up
		delete[] record;
	}
	return 0;
}
