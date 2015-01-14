#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main() {
	while (1) {
		int m = -1;
		int n = -1;
		scanf("%d%d", &m, &n);
		if (m == -1 || n == -1) {
			break;
		}

		int** matrix = malloc(sizeof(int*) * m);
		int i;
		int j;
		for (i = 0; i < m; ++i) {
			matrix[i] = malloc(sizeof(int) * n);
			for (j = 0; j < n; ++j) {
				matrix[i][j] = 0;
			}
		}
		/*read matrix*/
		for (j = 0; j < m; ++j) {
			int r;
			scanf("%d", &r);
			int* rowPos = malloc(sizeof(int) * r);
			for (i = 0; i < r; ++i) {
				scanf("%d", &rowPos[i]);
				rowPos[i]--;
			}
			for (i = 0; i < r; ++i) {
				if (rowPos[i] != -1) {
					scanf("%d", &matrix[j][rowPos[i]]);
				}
			}
			free(rowPos);
		}

		/*print their format*/
		printf("%d %d\n", n, m);
		for (i = 0; i < n; ++i) {
			int nonzeroes = 0;
			for (j = 0; j < m; ++j) {
				if (matrix[j][i]) {
					nonzeroes++;
				}
			}
			int* rowPos = malloc(sizeof(int) * nonzeroes);
			memset(rowPos, -1, nonzeroes);
			int k = 0;
			for (j = 0; j < m; ++j) {
				if (matrix[j][i]) {
					rowPos[k] = j;
					k++;
				}
			}
			if (nonzeroes == 0) {
				printf("0\n");
			} else {
				printf("%d ", nonzeroes);
				for (k = 0; k < nonzeroes; ++k) {
					printf("%d", rowPos[k] + 1);
					if (k < nonzeroes - 1)
						printf(" ");
				}
				printf("\n");
				for (k = 0; k < nonzeroes; ++k) {
					printf("%d", matrix[rowPos[k]][i]);
					if (k < nonzeroes - 1)
						printf(" ");
				}
			}
			printf("\n");
			free(rowPos);
		}
		for (i = 0; i < m; ++i) {
			free(matrix[i]);
		}
		free(matrix);
	}
	return 0;
}
