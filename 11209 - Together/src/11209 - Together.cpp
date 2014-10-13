#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;
typedef pair<int, int> vertex_distance;

struct compare {
	bool operator()(const vertex_distance& a, const vertex_distance& b) const {
		return a.second < b.second;
	}
};

void dfs(const graph& G, int s, int f, set<int>& visited,
		vector<vector<int>>& path) {
	if (s == f) {
		//reached destination, so start a new path
		path.push_back(vector<int>());
		return;
	}

	visited.insert(s);
	//put the point in the newest path
	path[path.size() - 1].push_back(s);
	cerr << "At point " << s << endl;
	for (unsigned i = 0; i < G[s].size(); ++i) {
		if (G[s][i] != -1 && visited.find(i) == visited.end()) {
			dfs(G, i, f, visited, path);
			visited.erase(i);
		}
	}
	cerr << "\tbottom of dfs" << endl;
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

		vector<vector<int>> pathJ;
		pathJ.push_back(vector<int>());
		set<int> visited;
		dfs(g, J - 1, W - 1, visited, pathJ);
		for (unsigned i = 0; i < pathJ.size() - 1; ++i) {
			for (unsigned j = 0; j < pathJ[i].size(); ++i) {
				cerr << pathJ[i][j] << " ";
			}
			cerr << endl;
		}
	}

	return 0;
}
