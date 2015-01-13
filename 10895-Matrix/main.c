#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int** matrix = malloc(sizeof(int*) * m);
	int i;
	for (i = 0; i < m; ++i) {
		matrix[i] = malloc(sizeof(int) * n);
		memset(matrix[i], 0, n);
	}
	int j;
	//read matrix
	for (j = 0; j < m; ++j) {
		int r;
		scanf("%d", &r);
		int* rowPos = malloc(sizeof(int) * r);
		memset(rowPos, -1, r);
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
	/*//XXX
	 //security print
	 printf("security print 1\n");
	 for (i = 0; i < m; ++i) {
	 for (j = 0; j < n; ++j) {
	 printf("%d ", matrix[i][j]);
	 }
	 printf("\n");
	 }
	 printf("\n\n");
	 //transpose
	 //	for (i = 0; i < n; ++i) {
	 //		for (j = 0; j < m; ++j) {
	 //			int temp = matrix[i][j];
	 //			matrix[i][j] = matrix[j][i];
	 //			matrix[j][i] = temp;
	 //		}
	 //	}
	 //from here out n&m have switched
	 //XXX
	 //security print
	 printf("security print 2\n");
	 for (i = 0; i < n; ++i) {
	 for (j = 0; j < m; ++j) {
	 printf("%d ", matrix[j][i]);
	 }
	 printf("\n");
	 }
	 printf("\n\n");*/

	//print their format
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
		printf("%d ", nonzeroes);
		for (k = 0; k < nonzeroes; ++k) {
			printf("%d ", rowPos[k] + 1);
		}
		printf("\n");
		for (k = 0; k < nonzeroes; ++k) {
			printf("%d ", matrix[rowPos[k]][i]);
		}
		printf("\n");
		free(rowPos);
	}
	for (i = 0; i < m; ++i) {
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
