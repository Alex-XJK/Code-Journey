#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Jiakai XU, July 19 2021, coding for OJ 356Poor Trade Advisor
//New Version after getting WA for so many times without figuring out reason

#define inf -2147483648

struct Wvertice
{
	int vername;
	int weight;
	Wvertice(int n, int w) :vername(n), weight(w) {}
};

template <class binumtype>
class AdjacencyList
{
public:
	/**
	* Create a pool of vectors that hold a Type with two integers.
	* @param n the number of vector(s) you need
	* @author Alex_XU
	*/
	AdjacencyList(int n) {
		adjlist = new vector<binumtype>[n];
		upperbound = n;
	}
	/**
	* Create a new element to one of the vectors in this pool.
	* @param at which vector you want the new element added to, starts from 1
	* @param val_a the first integer cell of {@code <binumtype>}
	* @param val_b the second integer cell of {@code <binumtype>}
	* @throw Index Out Of Bounds Exception
	*/
	void creat(int at, int val_a, int val_b) {
		if (!index_ok(at)) { return; }
		adjlist[at - 1].push_back(binumtype(val_a, val_b));
	}
	/**
	* Get the element size of specfied vector.
	* @param which which vector you want to know
	* @return	the size	if goes right;
	*			-1			if exception throws
	* @throw Index Out Of Bounds Exception
	*/
	int getSizeOf(int which) {
		if (!index_ok(which)) { return -1; }
		return adjlist[which - 1].size();
	}
	/**
	* Get the elements of specfied vector.
	* @param which which vector you want to know
	* @return the head iterator of that target
	*/
	auto retrieve(int which) {
		if (index_ok(which)) {
			return adjlist[which - 1].begin();
		}
	}
	/**
	* Get the whole specfied element.
	* @param which which vector you want to know
	* @return the single targeted vector
	* @throw Index Out Of Bounds Exception
	*/
	vector<binumtype> getVector(int target) {
		if (!index_ok(target)) { return; }
		return adjlist[target - 1];
	}
	~AdjacencyList() {
		delete[] adjlist;
	}
private:
	int upperbound;
	vector<binumtype>* adjlist;
	/**
	* Check whether the index number is valid
	* @param pendingCheckIndex the index number that pending checking
	* @return	true	if smaller than upper bound but non-negative;
	*			false	vice versa
	* @throw Index Out Of Bounds Exception
	*/
	inline bool index_ok(int pendingCheckIndex) {
		if (pendingCheckIndex - 1 < upperbound && pendingCheckIndex - 1 >= 0) {
			return true;
		}
		else {
			cout << "Index Out Of Bounds Exception: index [" << pendingCheckIndex << "] reach bound " << upperbound << endl;
			return false;
		}
	}
};


int N = 0, M = 0;
int maxPPA = inf;
bool isVisited[504];
AdjacencyList<Wvertice>* al = NULL;

void init();
int traversalnew(int sta);

int main() {
	while (cin >> N >> M) {
		//Break out condition
		if (N == 0 && M == 0) {
			break;
		}
		//Initialization
		init();
		//Read-in and build the adjacency list
		int x = 0, y = 0, w = 0;
		for (int i = M - 1; i >= 0; i--) {
			cin >> x >> y >> w;
			al->creat(x, y, w);
			al->creat(y, x, w);
			maxPPA = max(maxPPA, w);
		}
		//Compute the answer
		int answerCount = 0;
		for (int city = 1; city <= N; city++) {
			if (!isVisited[city]) {
				isVisited[city] = true;
				answerCount = max(answerCount, traversalnew(city));
			}
		}
		//Output result
		cout << answerCount << endl;
		//Clean AdjacencyList
		delete al;
	}
	return 0;
}

void init() {
	maxPPA = inf;
	al = new AdjacencyList<Wvertice>(N);
	for (int i = 1; i <= N; i++) {
		isVisited[i] = false;
	}
}

int traversalnew(int sta) {
	int cityCount = 1;
	vector<Wvertice>::iterator it = al->retrieve(sta);
	for (int i = al->getSizeOf(sta) - 1; i >= 0; i--) {
		if (isVisited[it->vername]) {}
		else if (it->weight != maxPPA) {}
		else {
			isVisited[it->vername] = true;
			cityCount += traversalnew(it->vername);
		}
		it++;
	}
	return cityCount;
}
