#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N, M, K;
		//N nodes
		//M paths
		//K # of cities in set A
		//N-K # of cities in set B
		cin >> N >> M >> K;
		for (int i = 0; i < M; ++i) {
			//list of paths from node u to node v with cost c
			int u, v, c;
			cin >> u >> v >> c;
		}
	}
}
