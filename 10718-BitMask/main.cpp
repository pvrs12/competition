#include <iostream>
#include <bitset>
#include <climits>

using namespace std;

bool operator<(bitset<32> a, bitset<32> b) {
	return a.to_ulong() < b.to_ulong();
}

bool operator>(bitset<32> a, bitset<32> b) {
	return a.to_ulong() > b.to_ulong();
}

int main() {
	while (true) {
		long long Ni, Li, Ui;
		Ni = Li = Ui = -1;
		cin >> Ni >> Li >> Ui;
		if (Ni == -1 && Li == -1 && Ui == -1) {
			break;
		}

		const bitset<32> N(Ni), L(Li), U(Ui);
		bitset<32> M(Li);
		//go through each bit
		//left to right, turn on and check if L <= M (don't need to check U because M starts equal to U)
		//for biggest N | M, turn on M if !N
		for (int i = 0; i < 32; ++i) {
			if (M > U) {
				break;
			}
			if (M[i] == N[i]) {
			//if they're the same, flip M
				M[i].flip();
				if (M > U) {
					//if that makes it bigger than U, un-flip
					M[i].flip();
				} else if (M < L) {
					// if it makes it less than L, un-flip
					M[i].flip();
				}
			}
		}

		cout << M.to_ulong() << endl;
	}
}
