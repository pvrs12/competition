#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> trie;

string* reverse(string* s, int len) {
	string* st = new string();
	for (int i = len; i >= 0; --i) {
		(*st) += (*s)[i];
	}
	return st;
}

struct compare {
	compare(string* s, int ordering = 0) :
			s(s), ordering(ordering) {
	}
	string* s;
	int ordering;

	bool operator()(int a, int b) const {
		if (ordering == 0)
			//alphabetical
			return strcmp(s->c_str() + a, s->c_str() + b) < 0;
		else
			//length (greatest to least)
			return strlen(s->c_str() + a) > strlen(s->c_str() + b);
	}
};

int stringMatching(const string& s, const trie& sa, const char* sub, int len) {
	int lo = 0, hi = len - 1, mid = lo;
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

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string* s = new string();
		cin >> *s;

		//build a suffix array of s
		trie SAs;
		trie SAr;
		for (unsigned i = 0; i < s->size(); ++i) {
			SAs.push_back(i);
			SAr.push_back(i);
		}
		sort(SAs.begin(), SAs.end(), compare(s, 0));

		string* reverseS = reverse(s, s->length() - 1);
		sort(SAr.begin(), SAr.end(), compare(reverseS, 1));

		for (unsigned i = 0; i < SAr.size(); ++i) {
			int a = stringMatching(*s, SAs, reverseS->c_str() + SAr[i],
					reverseS->length() - SAr[i]);
			if (a != -1) {
				cout << reverseS->c_str() + SAr[i] << endl;
				break;
			}
		}

		delete s;
		delete reverseS;
	}
	return 0;
}
