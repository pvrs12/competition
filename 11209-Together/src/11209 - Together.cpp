#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;

struct compare {
	bool operator()(const pair<vector<int>, pair<int, int>>& a,
			const pair<vector<int>, pair<int, int>>& b) const {
		return a.second.first < b.second.first;
	}
};

int distance(const graph& G, vector<int>& path) {
	int d = 0;
	for (unsigned i = 0; i < path.size() - 1; ++i) {
		d += G[path[i]][path[i + 1]];
	}
	return d;
}

int midpoint(const graph& G, vector<int>& path, int distance) {
	int dist = 0;
	for (unsigned i = 0; i < path.size() - 1; ++i) {
		dist += G[path[i]][path[i + 1]];
		if (dist == distance / 2) {
			return path[i + 1];
		}
		if (dist > distance / 2) {
			return -1;
		}
	}
	return -1;
}

bool dfs(const graph& G, int s, int f, vector<int>& visited,
		vector<vector<int>>& paths, int depth = 0) {

	visited.push_back(s);
	if (s == f) {
		paths[paths.size() - 1] = visited;
		//reached destination, so start a new paths
		paths.push_back(vector<int>());
		return true;
	}

	for (unsigned i = 0; i < G[s].size(); ++i) {
		if (G[s][i] != -1
				&& find(visited.begin(), visited.end(), i) == visited.end()) {
			dfs(G, i, f, visited, paths, depth + 1);
			visited.erase(find(visited.begin(), visited.end(), i));
		}
	}
	return false;
}

int main() {

	int k = 0;
	while (true) {
		int n, m, J, W;
		cin >> n;
		if (!n) {
			break;
		}
		if (k) {
			cout << endl;
		}
		k++;

		cin >> m >> J >> W;

		graph g(n, vector<int>(n, -1));

		for (int l = 0; l < m; ++l) {
			int i, j, d;
			cin >> i >> j >> d;
			g[i - 1][j - 1] = d;
			g[j - 1][i - 1] = d;
		}

		cout << "Case " << k << ": " << flush;

		vector<vector<int>> paths;
		paths.push_back(vector<int>());
		vector<int> visited;
		dfs(g, J - 1, W - 1, visited, paths);

#ifndef ONLINE_JUDGE
		cerr << "Paths from J (" << J << ") to W (" << W << "):" << endl;
		for (unsigned i = 0; i < paths.size() - 1; ++i) {
			cerr << distance(g, paths[i]) << ": ";
			for (unsigned j = 0; j < paths[i].size(); ++j) {
				cerr << paths[i][j] + 1 << " ";
			}
			cerr << endl;
		}
#endif

		vector<pair<vector<int>, pair<int, int>>> v;
		for (unsigned i = 0; i < paths.size() - 1; ++i) {
			int dist = distance(g, paths[i]);
			//all distances are integers, so any odd distance can't work
			if (dist % 2 == 0) {
				//try to find midpoint
				int a = midpoint(g, paths[i], dist);
				if (a != -1) {
					//add dist,midpoint to v
					v.push_back(
							pair<vector<int>, pair<int, int>>(paths[i],
									pair<int, int>(dist, a)));
				}
			}
		}
		//sort by distance ascending
		sort(v.begin(), v.end(), compare());

		//the shortest distance is now in v[0]
		//v[0].first = the path
		//v[0].second.first = the distance
		//v[0].second.second = the midpoint
		vector<int> finalPath = v[0].first;
		int distance = v[0].second.first;
		int midpoint = v[0].second.second;

		cout << distance / 2 << endl;

		int count = 0;
		for (unsigned i = 0; i < finalPath.size(); ++i) {
			count++;
			if (finalPath[i] == midpoint) {
				break;
			}
		}
		cout << count << " ";
		for (int i = 0; i < count - 1; ++i) {
			cout << finalPath[i] + 1 << " ";
		}
		cout << midpoint + 1;
		int backCount = finalPath.size() - count + 1;
		cout << endl << backCount << " ";
		for (unsigned i = finalPath.size() - 1;
				i >= finalPath.size() - backCount + 1; --i) {
			cout << finalPath[i] + 1 << " ";
		}
		cout << midpoint + 1;
		cout << endl;
	}

	return 0;
}
