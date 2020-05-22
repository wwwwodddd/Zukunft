#include <bits/stdc++.h>
using namespace std;
map<pair<string, string>, int> g;
int n;
string s;
long long z;
int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < 1 << n; i++) {
		string a, b;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				a += s[j];
			} else {
				b += s[j];
			}
		}
		g[{a, b}]++;
	}
	for (int i = 0; i < 1 << n; i++) {
		string a, b;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				a += s[2 * n - 1 - j];
			} else {
				b += s[2 * n - 1 - j];
			}
		}
		z += g[{a, b}];
	}
	cout << z << endl;
	return 0;
}