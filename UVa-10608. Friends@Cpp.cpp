#include<iostream>
using namespace std;

//Jiakai XU, Nov 17 2020, coding for OJ 142Friends

/**
* Implements "weighted quick union find" in Alg4
* Add the {@code maxSize} related methods to fit this question
*/
class WeightedQuickUF
{
public:
	WeightedQuickUF(int);
	~WeightedQuickUF();
	int getCount();
	int getMax();
	bool isConnected(int, int);
	int find(int);
	void makeUnion(int, int);
private:
	int* id;
	int* sz;
	int maxSize;
	int count;
};
WeightedQuickUF::WeightedQuickUF(int n) {
	id = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		id[i] = i;
	}
	sz = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		sz[i] = 1;
	}
	maxSize = 0;
	count = n;
}
WeightedQuickUF::~WeightedQuickUF() {
	delete[] id;
	delete[] sz;
}
int WeightedQuickUF::getCount() {
	return count;
}
int WeightedQuickUF::getMax() {
	return maxSize;
}
bool WeightedQuickUF::isConnected(int p, int q) {
	return find(p) == find(q);
}
int WeightedQuickUF::find(int p) {
	while (p != id[p]) {
		p = id[p];
	}
	return p;
}
/**
* Merges the set containing element {@code p} with the set containing element {@code q}.
* @param  p one element
* @param  q the other element
*/
void WeightedQuickUF::makeUnion(int p, int q) {
	int i = find(p);
	int j = find(q);
	if (i == j) return;
	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i];
		if (sz[j] > maxSize) {
			maxSize = sz[j];
		}
	}
	else {
		id[j] = i;
		sz[i] += sz[j];
		if (sz[i] > maxSize) {
			maxSize = sz[i];
		}
	}
	count--;
}

int main() {
	int testcase = 0;
	cin >> testcase;
	for (int tc = 0; tc < testcase; tc++) {
		int N = 0, M = 0;
		cin >> N >> M;
		WeightedQuickUF* wquf = new WeightedQuickUF(N);
		int A = 0, B = 0;
		for (int j = 0; j < M; j++) {
			cin >> A >> B;
			if (wquf->isConnected(A, B)) {
				continue;
			}
			wquf->makeUnion(A, B);
		}
		cout << wquf->getMax() << endl;
		delete wquf;
	}
	return 0;
}