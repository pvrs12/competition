#include <stdio.h>
#include <string.h>

int main() {
	int count;
	scanf("%d", &count);
	int i;
	for (i = 0; i < count; ++i) {
		char line[81];
		scanf("%s80", line);
		int len = strnlen(line, 80);
		int j;
		int small = 0;
		int total = 0;
		for (j = 0; j < len; ++j) {
			if (line[j] == 'O') {
				total += ++small;
			} else {
				small = 0;
			}
		}
		printf("%d\n", total);
	}
	return 0;
}
