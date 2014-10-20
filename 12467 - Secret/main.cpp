#include <iostream>
#include <string>

using namespace std;

string* reverse(string& sub) {
	string* s = new string();
	for (string::reverse_iterator i = sub.rbegin(); i != sub.rend(); ++i) {
		(*s) += *i;
	}
	return s;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string s;
		cin >> s;
		for (int j = s.size() - 1; j >= 0; --j) {
			string sub = s.substr(0, j);
			string* revsub = reverse(sub);
			int a = s.find(revsub->c_str());
			if (a != -1) {
				cout << *revsub << endl;
				delete revsub;
				break;
			}
			delete revsub;
		}
	}
	return 0;
}
