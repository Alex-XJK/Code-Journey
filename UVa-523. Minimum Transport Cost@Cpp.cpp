#include <iostream>
#include <cstring>
using namespace std;

//Jiakai XU, July 9 2021, coding for OJ 174Minimum Transport Cost

#define maxlength 1000
#define inf 9999999

int** graph = NULL;
int** path = NULL;
int* cost = NULL;

/**
* Compute how many word segment inside this string (separated by space)
* @param buffer the whole buffered string
* @return the number of segment components
*/
int getCount(char buffer[]) {
	int component = 0;
	int idx = 0;
	bool previousSpace = true;
	while (buffer[idx] != '\0') {
		if (buffer[idx] != ' ') {
			if (previousSpace) {
				previousSpace = false;
				component++;
			}
		}
		else {
			previousSpace = true;
		}
		idx++;
	}
	return component;
}

/**
* Change a string of digits into a integer array.
* If you not know the Parameter-2, call {@code getCount(char buffer[])} by yourself.
* @param target the destination array to store the integers
* @param source the source string that contains digits as characters
* @param len the estimated number of element that should store int the target
* @param error the value to represent belowe zero number, default value '-1'
* @throw Index out of range exception
*/
void buildArray(int* target, char* source, int len, int error = -1) {
	int idx = 0;
	bool previousSpace = true;
	int temp = 0;
	bool isMinus = false;
	for (int i = 1; i <= len; i++) {
		while (source[idx]!=' ' && source[idx] != '\0') {
			if (source[idx] == '-') {
				isMinus = true;
				temp = 0;
			}
			else {
				temp *= 10;
				temp += (int)source[idx] - 48;
			}
			idx++;
		}
		if (isMinus) {
			target[i] = error;
		}
		else {
			target[i] = temp;
		}
		temp = 0;
		isMinus = false;
		idx++;
	}
}

/**
* Implemented the standard version of Floyd Warshall algorithm for the shortest path finding process.
* @link https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
* Introduced in lecture by @author Kenneth Lee
* @param len the total length of node, start from 1
*/
void Floyd_Warshall(int len) {
	for (int k = 1; k <= len; k++) {
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= len; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j] + cost[k]) {
					graph[i][j] = graph[i][k] + graph[k][j] + cost[k];
					path[i][j] = path[i][k];
				}
			}
		}
	}
}

void printoutResult(int s, int e) {
	int total = graph[s][e];
	cout << "From " << s << " to " << e << " :" << endl;
	cout << "Path: " << s;
	while (s != e) {
		s = path[s][e];
		cout << "-->" << s;
	}
	cout << endl;
	cout << "Total cost : " << total << endl;
}

/**
* Debug print out the structure of adjacency list
*/
void printGraph(int** map, int len) {
	for (int i = 1; i <= len; i++) {
		cout << '\t' << i;
	}
	cout << endl << endl;
	for (int i = 1; i <= len; i++) {
		cout << i << ":";
		for (int j = 1; j <= len; j++) {
			int pg = map[i][j];
			if (pg == inf) {
				pg = -1;
			}
			cout << '\t' << pg;
		}
		cout << endl;
	}
}

int main() {
	int testcase = 0;
	cin >> testcase;
	char useless[5]; //Eat up new line break
	cin.getline(useless, 5);
	cin.getline(useless, 5);
	for (int tc = testcase - 1; tc >= 0; tc--) {
		//Get the city count
		char istr[maxlength];
		cin.getline(istr, maxlength - 1);
		int nodeN = getCount(istr);

		//Build the adjacency list --init
		graph = new int* [nodeN + 1];
		path = new int* [nodeN + 1];

		//Build the adjacency list --read in
		graph[1] = new int[nodeN + 1];
		path[1] = new int[nodeN + 1];
		buildArray(graph[1], istr, nodeN, inf);
		for (int i = 2; i <= nodeN; i++) {
			cin.getline(istr, maxlength - 1);
			graph[i] = new int[nodeN + 1];
			path[i] = new int[nodeN + 1];
			buildArray(graph[i], istr, nodeN, inf);
		}

		//Note down the tax cost
		cost = new int[nodeN + 1];
		for (int j = 1; j <= nodeN; j++) {
			cin >> cost[j];
		}

		//Init the next-path array
		for (int i = 1; i <= nodeN; ++i) {
			for (int j = 1; j <= nodeN; ++j) {
				path[i][j] = j;
			}
		}

		//Compute the shortest path
		Floyd_Warshall(nodeN);

		//Output
		char rstr[104];
		cin.getline(useless, 5);
		int respair[3];
		int caseCount = 0;
		while (true) {
			cin.getline(rstr, 100);
			if (strlen(rstr) < 2 || !rstr[0]) {
				break;
			}
			buildArray(respair, rstr, 2);
			if (caseCount) {
				cout << endl;
			}
			printoutResult(respair[1], respair[2]);
			caseCount++;
		}
		if (tc) {
			cout << endl;
		}

		//Clean up
		for (int i = nodeN; i > 0; i--) {
			delete[] graph[i];
			delete[] path[i];
		}
		delete[] path;
		delete[] graph;
		delete[] cost;
	}
	return 0;
}