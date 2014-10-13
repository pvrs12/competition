#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;
typedef pair<int, int> vertex_distance;

struct compare {
	bool operator()(const vertex_distance& a, const vertex_distance b) const {
		return a.second < b.second;
	}
};

pair<vector<int>, vector<int>> dijkstra(graph g, unsigned source) {
	vector<int> dist(g.size());
	dist[source] = 0;
	vector<int> previous(g.size());

	priority_queue<vertex_distance, vector<vertex_distance>, compare> q;

	for (unsigned i = 0; i < g.size(); ++i) {
		if (i != source) {
			dist[i] = INT_MAX;
			previous[i] = -1;
		}
		q.push(vertex_distance(i, dist[i]));
	}

	while (!q.empty()) {
		vertex_distance u = q.top();
		q.pop();
		for (unsigned j = 0; j < g[u.first].size(); j++) {
			int v = g[u.first][j];
			if (v != -1) {
				if (dist[v] == INT_MAX) {
					int alt = u.second + g[u.first][v];
					if (alt < dist[v]) {
						dist[v] = alt;
						previous[v] = u.first;
					}
				}
			}
		}
	}
	return pair<vector<int>, vector<int>>(dist, previous);
}

int main() {

	int k = 0;
	while (true) {
		k++;
		int n, m, J, W;
		cin >> n;
		if (!n)
			break;

		cin >> m >> J >> W;

		graph g(n, vector<int>(n, -1));

		for (int l = 0; l < m; ++l) {
			int i, j, d;
			cin >> i >> j >> d;
			g[i - 1][j - 1] = d;
			g[j - 1][i - 1] = d;
		}

		cout << "Case " << k << ": ";
		pair<vector<int>, vector<int>> jpath = dijkstra(g, J);
		for (unsigned i = 0; i < jpath.first.size(); ++i) {
			cout << "Distance for J to " << i << " is " << jpath.first[i]
					<< endl;
		}
		pair<vector<int>, vector<int>> wpath = dijkstra(g, W);
		for (unsigned i = 0; i < jpath.first.size(); ++i) {
			cout << "Distance for W to " << i << " is " << jpath.first[i]
					<< endl;
		}

	}

	return 0;
}
