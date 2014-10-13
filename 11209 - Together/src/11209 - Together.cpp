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

bool dfs(const graph& G, int s, int f, set<int>& visited,
		vector<pair<set<int>, int>>& path, int previous = -1) {
	visited.insert(s);
	//put the point in the newest path
	if (previous != -1) {
		path[path.size() - 1].first.insert(previous);
		path[path.size() - 1].second += G[previous][s];
	}

	if (s == f) {
		path[path.size() - 1].first.insert(s);
		//reached destination, so start a new path
		path.push_back(pair<set<int>, int>(set<int>(), 0));
		return true;
	}

	visited.insert(s);
	for (unsigned i = 0; i < G[s].size(); ++i) {
		if (G[s][i] != -1 && visited.find(i) == visited.end()) {
			dfs(G, i, f, visited, path, s);
			visited.erase(i);
		}
	}
	return false;
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

		vector<pair<set<int>, int>> pathJ;
		pathJ.push_back(pair<set<int>, int>(set<int>(), 0));
		set<int> visited;
		dfs(g, J - 1, W - 1, visited, pathJ);
		cerr << "Paths from J (" << J << ") to W (" << W << "):" << endl;
		for (unsigned i = 0; i < pathJ.size() - 1; ++i) {
			cerr << pathJ[i].second << ": ";
			for (auto j = pathJ[i].first.begin(); j != pathJ[i].first.end();
					++j) {
				cerr << *j << " ";
			}
			cerr << endl;
		}
	}

	return 0;
}
