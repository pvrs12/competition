#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;
typedef pair<int, int> vertex_distance;

struct compare {
	bool operator()(const vertex_distance& a, const vertex_distance b) const {
		return a.second < b.second;
	}
};

vector<vector<int>> bfs(const graph& G, int J, int W){
	//do a bfs from J to W on G
	queue<int> q;
	vector<int> v;
	
	v.push_back(J);
	q.push(J);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		if(t==W){
			//the path should be in v... kind of
		}
		for(unsigned i=0;i<G[J].size();++i){
			int u = G[J][i];
			if(u!=-1){
				if(!(find(v.begin(),v.end(),u) != v.end())){
					v.push_back(u);
					q.push(u);
				}
			}
		}
	}
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

	}

	return 0;
}
