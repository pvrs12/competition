#include <math.h>
#include <stdio.h>

int main() {
	unsigned long long triangleMemo[1000010];
	triangleMemo[3] = 0;
	long i;
	for (i = 4; i <= 1000000; ++i) {
		unsigned long long count = ((i - 2) * (i - 2)) / 4;
		triangleMemo[i] = count + triangleMemo[i - 1];
	}
	while (1) {
		long long n;
		scanf("%lld", &n);
		if (n < 3) {
			return 0;
		}
		printf("%llu\n", triangleMemo[n]);
	}
}
