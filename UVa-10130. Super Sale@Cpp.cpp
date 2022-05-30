#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize(2)
//#pragma warning(disable : 4996)

//Jiakai XU, August 8 2021, coding for OJ 218SuperSale

struct Item
{
	int price;
	int weight;
};

Item* itemlist = nullptr;
int rule[36];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("218.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	int testcase = 0;
	cin >> testcase;
	for (int tc = testcase - 1; tc >= 0; tc--) {
		//Read in item info
		int itemnumber = 0;
		cin >> itemnumber;
		itemlist = new Item[itemnumber];
		for (int i = 0; i < itemnumber; i++) {
			cin >> itemlist[i].price;
			cin >> itemlist[i].weight;
		}
		//DP compute - init
		for (int idx = 30; idx >= 0; idx--) {
			rule[idx] = 0;
		}
		//DP compute - main
		for (int i = 0; i < itemnumber; i++) {
			int iprice = itemlist[i].price;
			int iweight = itemlist[i].weight;
			for (int w = 30; w >= iweight; w--) {
				rule[w] = max(rule[w], rule[w - iweight] + iprice);
			}
		}
		//Judge people one-by-one
		int answer = 0;
		int totalpeople = 0, lift = 0;
		cin >> totalpeople;
		for (int p = totalpeople - 1; p >= 0; p--) {
			cin >> lift;
			answer += rule[lift];
		}
		//Print out
		cout << answer << "\n";
		//Clean up
		delete[] itemlist;
		itemlist = nullptr;
	}
	return 0;
}