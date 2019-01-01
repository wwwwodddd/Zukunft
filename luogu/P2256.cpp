#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[20020];
map<string, int> g;
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		g[s] = i;
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		U(g[a], g[b]);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		if (F(g[a]) == F(g[b])) {
			cout << "Yes." << endl;
		} else {
			cout << "No." << endl;
		}
	}
	return 0;
}