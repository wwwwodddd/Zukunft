#include <bits/stdc++.h>
using namespace std;
int gao(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	if (s.size() % 2 == 0 && t == s) {
		return gao(s.substr(0, s.size() / 2));
	} else {
		return s.size();
	}
}
int main() {
	string s;
	cin >> s;
	cout << gao(s) << endl;
}