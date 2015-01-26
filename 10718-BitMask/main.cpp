#include <iostream>
#include <bitset>

using namespace std;

bool operator<(bitset<32> a, bitset<32> b) {
	return a.to_ulong() < b.to_ulong();
}

bool operator>(bitset<32> a, bitset<32> b) {
	return a.to_ulong() > b.to_ulong();
}

int main() {
	while (true) {
		unsigned int Ni, Li, Ui;
		Ni = Li = Ui = 0;
		cin >> Ni >> Li >> Ui;
		if (!Ni && !Li && !Ui) {
			break;
		}

		bitset<32> M(Ui), N(Ni), L(Li), U(Ui);
		//go through each bit
		//left to right, turn on and check if L <= M (don't need to check U because M starts equal to U)
		//for biggest N | M, turn on M if !N
		for (int i = 31; i >= 0; --i) {
			//if they're the same, flip M
			if (M[i] == N[i]) {
				M[i].flip();
				//if that makes it bigger than U, un-flip
				if (M > U) {
					M[i].flip();
				} // if it makes it less than L, un-flip
				else if (M < L) {
					M[i].flip();
				}
			}
		}

		cout << M.to_ulong() << endl;
	}
}
