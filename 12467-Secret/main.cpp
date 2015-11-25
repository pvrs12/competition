#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> trie;

string* reverse(string* s, unsigned len) {
	string* st = new string();
	for (unsigned i = len; i >= 0; --i) {
		(*st) += (*s)[i];
	}
	return st;
}

int stringMatching(const string& s, const trie& sa, const char* sub,
		unsigned len) {
	int lo = 0, hi = s.length() - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(s.c_str() + sa[mid], sub, len);
		if (res >= 0) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	if (strncmp(s.c_str() + sa[lo], sub, len) != 0) {
		return -1;
	}
	return lo;
}

void countingSort(int k, string& s, vector<char>& RA, trie& SA, trie& tempSA) {
	unsigned maxi = max((unsigned) 300, (unsigned) s.length());
	vector<int> c(maxi + 10, 0);
	for (unsigned i = 0; i < s.length(); ++i) {
		c[i + k < s.length() ? RA[i + k] : 0]++;
	}
	int sum = 0;
	for (unsigned i = 0; i < maxi; ++i) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (unsigned i = 0; i < s.length(); ++i) {
		tempSA[c[SA[i] + k < (int) s.length() ? RA[SA[i] + k] : 0]++] = SA[i];
	}
	for (unsigned i = 0; i < s.length(); ++i) {
		SA[i] = tempSA[i];
	}
}

trie* constructSA(string* s) {
	vector<char> RA(s->length()), tempRA(s->length());
	trie* SA = new trie(s->length()), tempSA(s->length());
	for (unsigned i = 0; i < s->length(); ++i) {
		RA[i] = (*s)[i];
		tempRA[i] = (*s)[i];
	}
	for (unsigned i = 0; i < s->length(); ++i) {
		(*SA)[i] = i;
	}
	for (unsigned k = 1; k < s->length(); k <<= 1) {
		countingSort(k, *s, RA, *SA, tempSA);
		countingSort(0, *s, RA, *SA, tempSA);
		unsigned r = 0;
		tempRA[(*SA)[0]] = 0;
		for (unsigned i = 1; i < s->length(); ++i) {
			tempRA[(*SA)[i]] =
					(RA[(*SA)[i]] == RA[(*SA)[i - 1]]
							&& RA[(*SA)[i] + k] == RA[(*SA)[i - 1] + k]) ?
							r : ++r;
		}
		for (unsigned i = 0; i < s->length(); ++i) {
			RA[i] = tempRA[i];
		}
		if (RA[(*SA)[s->length() - 1]] == (int) s->length() - 1) {
			break;
		}
	}
	return SA;
}

int main() {
	//fuck this shit
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string* s = new string();
		cin >> *s;

		//build a suffix array of s and reversed s
		//this step is O(n log n)
		cout << "building trie" << endl;
		trie* SAs = constructSA(s);
		cout << "done building trie" << endl;

		string* reverseS = reverse(s, s->length() - 1);

//		for (unsigned i = 0; i < SAs->size(); ++i) {
//			cout << s->c_str() + (*SAs)[i] << endl;
//		}

		for (unsigned i = 0; i < reverseS->length(); ++i) {
			int a = stringMatching(*s, *SAs, reverseS->c_str() + i,
					reverseS->length() - i);
			if (a != -1) {
				cout << reverseS->c_str() + i << endl;
				break;
			}
		}

		delete s;
		delete SAs;
		delete reverseS;
	}
	return 0;
}
