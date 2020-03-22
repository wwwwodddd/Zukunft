#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
map<string, bool> g;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		g[s] = false;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (g.find(s) == g.end()) {
			cout << "WRONG" << endl;
		} else {
			cout << (g[s] ? "REPEAT" : "OK") << endl;
			g[s] = true;
		}
	}
	return 0;
}