#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> trie;

string* reverse(const string& s, int len) {
	string* st = new string();
	for (int i = len; i >= 0; --i) {
		(*st) += s[i];
	}
	return st;
}

struct compare {
	compare(string* s) :
			s(s) {
	}
	string* s;

	bool operator()(int a, int b) const {
		return strcmp(s->c_str() + a, s->c_str() + b) < 0;
	}
};

int stringMatching(const string& s, const trie& sa, const string& sub) {
	int lo = 0, hi = s.length() - 1, mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(s.c_str() + sa[mid], sub.c_str(), sub.length());
		if (res >= 0) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	if (strncmp(s.c_str() + sa[lo], sub.c_str(), sub.length()) != 0) {
		return -1;
	}
	return lo;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string s;
		cin >> s;

		//build a trie of s
		trie SA;
		for (unsigned i = 0; i < s.size(); ++i) {
			SA.push_back(i);
		}
		sort(SA.begin(), SA.end(), compare(s));

		//O(n^2 * log(n)
		for (int j = s.size() - 1; j >= 0; --j) {
			string* revsub = reverse(s, j);
			//O(n*log(n))
			int res = stringMatching(s, SA, *revsub);
			if (res != -1) {
				cout << *revsub << endl;
				delete revsub;
				break;
			}
			delete revsub;
		}
	}
	return 0;
}
