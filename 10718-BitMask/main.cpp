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
		bitset<32> M(0);
		//cout << N << endl;

		bool less = false;
		for (int i = 32; i >= 0; --i) {
			//go through comparing with U and N to build M
			if (!U[i] && N[i]) {
				//U[i]==0
				//N[i]==1
				//do nothing
			} else if (U[i] && N[i]) {
				//U[i]==1
				//N[i]==1
				//i am now less than U no matter what I do in M
				less = true;
			} else if (U[i] && !N[i]) {
				//U[i]==1
				//N[i]==0
				//do nothing
				//because it makes sense to leave M at 0 for lower values
				//we are now less than U
				less = true;
			} else if (!U[i] && !N[i]) {
				//U[i]==0
				//N[i]==0
				//have to check if it is definitely less, otherwise we can't flip
				if (less) {
					M[i].flip();
				}
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
