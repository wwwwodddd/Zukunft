#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int a[520][520];
int d[520];
int s[1050], ss;
void dfs(int x) {
	for (int i = 1; i <= n; i++) {
		if (a[x][i] > 0) {
			a[x][i]--;
			a[i][x]--;
			dfs(i);
		}
	}
	s[ss] = x;
	ss--;
}
int main() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x][y]++;
		a[y][x]++;
		d[x]++;
		d[y]++;
		n = max(n, max(x, y));
	}
	int start = 1;
	for (int i = 1; i <= n; i++) {
		if (d[i] & 1) {
			start = i;
			break;
		}
	}
	ss = m;
	dfs(start);
	for (int i = 0; i <= m; i++) {
		cout << s[i] << endl;
	}
	return 0;
}