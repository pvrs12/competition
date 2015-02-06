#include <stdio.h>
#include <malloc.h>
#include <limits.h>

int solve(int* data, int start, int len) {
	if (len <= 2) {
		//find k
		int k = data[start + len - 1] - data[start];
		return k;
	}
	int k1 = solve(data, start, len / 2);
	int k2 = solve(data, len / 2, len / 2);
	return k1 > k2 ? k1 : k2;
}

int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		int j;
		int* data = malloc(sizeof(int) * m);
		int minK = INT_MAX;
		for (j = 0; j < m; ++j) {
			scanf("%d", &data[j]);
			//for each pair, determine the `k` necessary to move to the next level
			//then on merge find the lowest k needed
			int k = solve(data, 0, m);
			if (k < minK) {
				minK = k;
			}
		}
		printf("%d\n", minK);
		free(data);
	}
	return 0;
}
