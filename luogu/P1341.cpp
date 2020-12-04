#include <bits/stdc++.h>
using namespace std;
int n = 256, m, ss;
char x, y;
int a[520][520];
int d[520];
char s[1050];
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
	}
	int start = -1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] & 1) {
			if (start == -1) {
				start = i;
			}
			cnt++;
		}
	}
	if (cnt > 2) {
		cout << "No Solution" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] > 0) {
			if (start == -1) {
				start = i;
			}
		}
	}
	ss = m;
	dfs(start);
	if (ss == -1) {
		for (int i = 0; i <= m; i++) {
			cout << s[i];
		}
	} else {
		cout << "No Solution";
	}
	cout << endl;
	return 0;
}