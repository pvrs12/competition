#include <iostream>
#include <vector>

using namespace std;

bool isCycle(const vector<int>& djs, int root,
		vector<bool>* visited = nullptr) {

	if (visited == nullptr) {
		visited = new vector<bool>(djs.size(), false);
	}
	if (root == -1) {
		delete (visited);
		return false;
	}
	if (visited->at(root)) {
		delete (visited);
		return true;
	}
	visited->at(root) = true;
	return isCycle(djs, djs[root], visited);
}

int findRoot(const vector<int>& djs, int root) {
	if (root == -1) {
		return root;
	}
	int ret = findRoot(djs, djs[root]);
	if (ret == -1) {
		return root;
	} else {
		return ret;
	}
}

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int n, m;
		cin >> n >> m;
		//n citizens
		//m friendships
		vector<int> djs(n + 1, -1);
		vector<int> rootCount(n + 1, 0);
		int biggest = 0;
		int cycle = 0;
		for (int j = 0; j < m; ++j) {
			int p1, p2;
			cin >> p1 >> p2;
			djs[p2] = p1;
			if (isCycle(djs, p2)) {
				cycle++;
				//undo what you just did
				djs[p2] = -1;
			}
			int count = ++rootCount[findRoot(djs, p2)];
			biggest = max(count, biggest);
		}
		biggest += (1 - cycle);
		cout << biggest << endl;
	}
	return 0;
}
