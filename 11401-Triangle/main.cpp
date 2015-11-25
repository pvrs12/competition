#include <cmath>
#include <iostream>

using namespace std;

int main() {
	unsigned long long triangleMemo[1000001];
	triangleMemo[3] = 0;
	for (long i = 4; i <= 1000000; ++i) {
		unsigned long long count = floor(((i - 2) * (i - 2)) / 4.);
		triangleMemo[i] = count + triangleMemo[i - 1];
	}
	while (true) {
		unsigned long long n;
		cin >> n;
		if (n == 0) {
			break;
		}
		cout << triangleMemo[n] << endl;
	}
}
