#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//Jiakai XU, July 31 2021, coding for OJ 176Internet Bandwidth

const int MAX_N = 104;	//Required 100
const int inf = 1024;	//Required greater than 1000;

int N, C;
int source, sink;
int Capacity[MAX_N][MAX_N];
int Flow[MAX_N][MAX_N];
int Bottleneck[MAX_N];
int previous[MAX_N];

/**
 * Initialize all the arrays to zero.
 */
void init() {
	for (int i = N; i >= 0; --i) {
		for (int j = N; j >= 0; --j) {
			Capacity[i][j] = 0;
			Flow[i][j] = 0;
		}
	}
}

/**
 * Given a standard queue, pop-up and return the first element. 
 */
template <typename T>
inline T que_pop(queue<T>* que) {
	if (que->empty()) {
		cout << "Empty Queue Exception!" << endl;
		return NULL;
	}
	T result = que->front();
	que->pop();
	return result;
}

void debugPrint(int gra[MAX_N][MAX_N]) {
	//Print out test
	cout << "+----\t";
	for (int i = 1; i <= N; ++i) {
		cout << i << " -\t";	
	}
	cout << endl;
	for (int i = 1; i <= N; ++i) {
		cout << i << " -\t";
		for (int j = 1; j <= N; ++j) {
			cout << Capacity[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void readIn() {
	int a = 0, b = 0, bandwidth = 0;
	cin >> source >> sink >> C;
	for (int connection = C - 1; connection >= 0; --connection) {
		cin >> a >> b >> bandwidth;
		Capacity[a][b] += bandwidth;
		Capacity[b][a] += bandwidth;
	}
	//debugPrint(Capacity);
}

void updateFlow(int flow) {
	for (int i = sink; i != source;) {
		Flow[previous[i]][i] += flow;
		Flow[i][previous[i]] -= flow;  // opposite edge
		i = previous[i];
	}
}

int MaxFlow() {
    int result = 0;
    while (true) {
    	//Local init
		for (int i = N; i >= 0; --i) {
			Bottleneck[i] = 0;		
		}
        queue<int> bfs;
		bfs.push(source);
		Bottleneck[source] = inf;

        while (!bfs.empty() && Bottleneck[sink] == 0) { //Still have path and destination not visited
			const int curr = que_pop(&bfs);
            for (int next = 1; next <= N; ++next) {
                if (Bottleneck[next] == 0 && Capacity[curr][next] > Flow[curr][next]) {
					bfs.push(next);
                    previous[next] = curr;
					Bottleneck[next] = min(Bottleneck[curr], (Capacity[curr][next] - Flow[curr][next]));
                }
            }
        }
		if (Bottleneck[sink] == 0) { //No valid path towards destination
			break;
		}
		else { //Update values
			updateFlow(Bottleneck[sink]);
			result += Bottleneck[sink];
		}
    }
    return result;
}

int main() {
	int testCase = 0;
	while (cin >> N) {
		//Break out condition
		if (N < 2 || N>100) {
			break;
		}
		testCase++;
		init();
		readIn();
		const int answer = MaxFlow();
		//Final Print-out
		cout << "Network " << testCase << endl;
		cout << "The bandwidth is " << answer << "." << endl;
		cout << endl;
	}
	return 0;
}