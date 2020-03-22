#include <bits/stdc++.h>
using namespace std;
unsigned get() {
	string s;
	cin >> s;
	unsigned re = 0;
	for (int i = 0; i < s.size(); i++) {
		re = (re * 131) ^ s[i];
	}
	return re;
}
int main() {
	set<unsigned> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		s.insert(get());
	}
	cout << s.size() << endl;
	return 0;
}