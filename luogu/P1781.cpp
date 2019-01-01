#include <bits/stdc++.h>
using namespace std;
string s[30];
int n, x;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i].size() > s[x].size() || s[i].size() == s[x].size() && s[i] > s[x]) {
			x = i;
		}
	}
	cout << (x + 1) << endl;
	cout << s[x] << endl;
	return 0;
}