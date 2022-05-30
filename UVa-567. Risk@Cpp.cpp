#include <iostream>
#include <stdio.h>
using namespace std;

//Jiakai XU, June 29 2021, coding for OJ 126Risk

#define inf 99999
#define len 20

int graph[len + 1][len + 1];//Adjacency Matrix

void initialization();
void Floyd_Warshall();
void debugprint();

int main() {
	int nodelength = 0;
	int input = 0;
	int testset = 0;
	while (cin >> nodelength) {
		//init
		initialization();
		testset += 1;

		//For node #1
		for (int i = nodelength - 1; i >= 0; i--) {
			cin >> input;
			graph[1][input] = 1;
			graph[input][1] = 1;
		}

		//For node #2-20
		for (int idx = 2; idx < len; idx++) {
			cin >> nodelength;
			for (int i = nodelength - 1; i >= 0; i--) {
				cin >> input;
				graph[idx][input] = 1;
				graph[input][idx] = 1;
			}
		}

		//Do the calculation
		Floyd_Warshall();
		//debugprint();

		//Input question and give output
		int testcase = 0;
		int s = 0, e = 0;
		cin >> testcase;
		printf("Test Set #%d\n", testset);
		for (int tc = 1; tc <= testcase; tc++) {
			cin >> s >> e;
			printf("%2d to %2d: %d\n", s, e, graph[s][e]);//Not sure about the meaning of "column" in question paper?
		}
		cout << endl;
	}
	return 0;
}

/**
* Initialize each value of the matrix as INF, except that the diagonal is 0.
*/
void initialization() {
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			graph[i][j] = inf;
		}
		graph[i][i] = 0;
	}
}

/**
* Implemented the standard version of Floyd Warshall algorithm for the shortest path finding process.
* @link https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
* Introduced in lecture by @author Kenneth Lee
*/
void Floyd_Warshall() {
	for (int k = 1; k <= len; k++) {
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= len; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

/**
* For debug use only.
* Print out the Adjacency Matrix called graph[][]
*/
void debugprint() {
	cout << "\t";
	for (int k = 1; k <= len; k++) {
		cout << k << "\t";
	}
	cout << endl;
	for (int i = 1; i <= len; i++) {
		cout << ">> " << i << "\t";
		for (int j = 1; j <= len; j++) {
			if (graph[i][j] != inf) {
				cout << graph[i][j] << "\t";
			}
			else {
				cout << "-- \t";
			}
		}
		cout << endl;
	}
}
