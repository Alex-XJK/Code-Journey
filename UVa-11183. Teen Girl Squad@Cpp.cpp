#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#pragma GCC optimize(2)
#pragma warning(disable : 4996)

//Jiakai XU, October 10 2021, coding for OJ 147 Teen Girl Squad (UVA11183)

const int MAXNODE = 1005;
const int MAXEDGE = 40005;
const int INF = 0x3f3f3f3f;

struct Edge {
	int u;
	int v;
	int dist;
	Edge(){}
	Edge(int nodeU, int nodeV, int distance) : u(nodeU), v(nodeV), dist(distance) {}
};

class Directed_MST {
public:
	Directed_MST(int n) {
		this->n = n;
		m = 0;
	}

	void add_Edge(int u, int v, int dist) {
		this->add_Edge(Edge(u, v, dist));
	}

	void add_Edge(Edge e) {
		edges[m++] = e;
	}

	int dir_mst(int root) {
		int ans = 0;
		while (true) {
			for (int i = 0; i < n; i++) {
				in[i] = INF;
			}
			for (int i = 0; i < m; i++) {
				int u = edges[i].u;
				int v = edges[i].v;
				if (edges[i].dist < in[v] && u != v) {
					in[v] = edges[i].dist;
					pre[v] = u;
				}
			}

			for (int i = 0; i < n; i++) {
				if (i == root) {
					continue;
				}
				if (in[i] == INF) {
					return -1;
				}
			}

			int cnt = 0;
			memset(id, -1, sizeof(id));
			memset(vis, -1, sizeof(vis));
			in[root] = 0;
			for (int i = 0; i < n; i++) {
				ans += in[i];
				int v = i;
				while (vis[v] != i && id[v] == -1 && v != root) {
					vis[v] = i;
					v = pre[v];
				}
				if (v != root && id[v] == -1) {
					for (int u = pre[v]; u != v; u = pre[u]) {
						id[u] = cnt;
					}
					id[v] = cnt++;
				}
			}
			if (cnt == 0) {
				break;
			}
			for (int i = 0; i < n; i++) {
				if (id[i] == -1) {
					id[i] = cnt++;
				}
			}
			for (int i = 0; i < m; i++) {
				int v = edges[i].v;
				edges[i].u = id[edges[i].u];
				edges[i].v = id[edges[i].v];
				if (edges[i].u != edges[i].v) {
					edges[i].dist -= in[v];
				}
			}
			n = cnt;
			root = id[root];
		}
		return ans;
	}

private:
	int n, m;
	Edge edges[MAXEDGE];
	int vis[MAXNODE];
	int pre[MAXNODE];
	int id[MAXNODE];
	int in[MAXNODE];
};

int N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	int testcase = 0;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++) {
		cin >> N >> M;
		Directed_MST* dmst = new Directed_MST(N);

		//Read in data
		int u, v, d;
		while (M--) {
			cin >> u >> v >> d;
			dmst->add_Edge(u, v, d);
		}

		//Compute result
		int result = dmst->dir_mst(0);

		//Final Print Out
		cout << "Case #" << tc << ": ";
		if (result == -1) {
			cout << "Possums!" << endl;
		}
		else {
			cout << result << endl;
		}
		
	}
	return 0;
}



