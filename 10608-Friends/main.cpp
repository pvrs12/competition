#include <iostream>
#include <vector>

using namespace std;

int findDepth(const vector<int>& djs, int root, int depth, vector<bool>& seen) {
	if (root == -1) {
		return depth;
	}
	if (seen[root]) {
		return depth;
	}
	seen[root] = true;
	return findDepth(djs, djs[root], depth + 1, seen);
}

int findDepth(const vector<int>& djs, int root) {
	vector<bool> v(false, djs.size());
	return findDepth(djs, djs[root], 0, v);
}

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int n, m;
		cin >> n >> m;
		//n citizens
		vector<int> djs(n + 1, -1);
		int biggest = 0;
		for (int j = 0; j < m; ++j) {
			int p1, p2;
			cin >> p1 >> p2;
			djs[p2] = p1;
			int depth = findDepth(djs, p2);
			if (depth > biggest) {
				biggest = depth;
			}
		}
		cout << biggest << endl;
	}
}
