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
		bitset<32> M(~Ni);
		//M[0] is right-most (LSB)

		//go from MSB to LSB, if it is greater than U, need to flip
		for (int i = 31; i >= 0; --i) {
			if (M[i] == 1 && U[i] == 0) {
				//greater than U, got to flip this bit
				M[i].flip();
			} else if (M[i] == 0 && U[i] == 1) {
				//we are definitely less
				//no flip because that would make us bigger
				break;
			}
		}

		//go from MSB to LSB, if it is less than L, need to flip
		for (int i = 31; i >= 0; --i) {
			if (M[i] == 0 && L[i] == 1) {
				//less than L, got to flip this bit
				M[i].flip();
			} else if (M[i] == 1 && L[i] == 0) {
				//we are definitely greater
				//and the lowest possible becuase we are ~N
				break;
			}
		}

		for (int i = 32; i >= 0; --i) {
			//compare M with L to fix M to be greater than L
			if (!L[i] && M[i]) {
				//L[i]==0
				//M[i]==1
				//too big must flip bit
				M[i].flip();
			} else if (L[i] && M[i]) {
				//L[i]==1
				//M[i]==1
				//same size
				//do nothing
				//no need to check for a flip here because we minimized before
			} else if (!L[i] && !M[i]) {
				//L[i]==0
				//M[i]==0
				//same size
				//do nothing
			} else if (L[i] && !M[i]) {
				//L[i]==1
				//M[i]==0
				//i am definitely smaller
				break;
			}
		}
		cout << M.to_ulong() << endl;
	}
}
