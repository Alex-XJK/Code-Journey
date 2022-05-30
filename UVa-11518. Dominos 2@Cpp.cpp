#include <iostream>
#include <vector>
using namespace std;

//Jiakai XU, June 23 2021, coding for OJ 134Dominos 2

class RecordArray
{
public:
	RecordArray(int length) {
		count = 0;
		isDown = new bool[length + 1];
		for (int i = length; i > 0; i--) {
			isDown[i] = false;
		}
	}
	/**
	* Update the status of a target position.
	* @param	pos	the target position, start from 1
	* @return	true	if is a newly knocked-down item; 
	*			false	if already down before hand. 
	*/
	bool update(int pos) {
		if (isDown[pos]) {
			//progressPrint(false, pos); //Debug use only
			return false;
		}
		else {
			isDown[pos] = true;
			count++;
			//progressPrint(true, pos); //Debug use only
			return true;
		}
	}
	int getCount() {
		return count;
	}
	void progressPrint(bool sta, int tar) {
		if (sta) {
			cout << "Node # " << tar << " is down now! Total count as " << count << endl;
		}
		else {
			cout << "Node # " << tar << " already down before!" << endl;
		}
	}
	~RecordArray() {
		delete[] isDown;
	}
private:
	int count;
	bool* isDown = NULL;
};

vector<int>* adl = NULL;

void printlist(int);
void operate(int, RecordArray&);

int main() {
	int testcase = 0;
	cin >> testcase;
	for (int tc = testcase - 1; tc >= 0; tc--) {
		//Build strcture
		int nodenum = 0, infolen = 0, kolen = 0;
		cin >> nodenum >> infolen >> kolen;
		adl = new vector<int>[nodenum + 1];
		RecordArray ra(nodenum);

		//Input infomation
		int active = 0, passive = 0;
		for (int i = infolen - 1; i >= 0; i--) {
			cin >> active >> passive;
			adl[active].push_back(passive);
		}
		//printlist(nodenum); //Debug use only

		//Knock over
		int target = 0;
		for (int i = kolen - 1; i >= 0; i--) {
			cin >> target;
			operate(target, ra);
		}

		//Output answer
		cout << ra.getCount() << endl;

		//Clear up
		delete[] adl;
	}
	return 0;
}

/**
* Print out the whole structure of the Adjacency List.
* @param	snlen	the total length of the nodes
*/
void printlist(int snlen) {
	vector<int>::iterator it;
	int linkedsize = 0;
	cout << "Printing Adjacency List" << endl;
	for (int snode = 1; snode <= snlen; snode++) {
		it = adl[snode].begin();
		linkedsize = adl[snode].size();
		cout << "Starting node #" << snode << " --> ";
		for (int lnode = linkedsize - 1; lnode >= 0; lnode--) {
			cout << *it << " - ";
			++it;
		}
		cout << endl;
	}
}

/**
* Operate a target position, using DFS-style method.
* @param	pos		the target position, start from 1
* @param	r		the built RecordArray object
*/
void operate(int pos, RecordArray& r) {
	if (!r.update(pos)) { //Already visited
		return;
	}
	vector<int>::iterator it = adl[pos].begin();
	int linkedsize = adl[pos].size();
	for (int lnode = linkedsize - 1; lnode >= 0; lnode--) {
		operate(*it, r);
		++it;
	}
}