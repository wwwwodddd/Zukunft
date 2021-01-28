#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> a[100020];
int f[100020][20];
int d[100020];
int c[200020];
int w[100020];
int L[100020];
int R[100020];
int ss = 1;
void change(int x, int y) {
	for (int i = x; i <= 2 * n; i += i & -i) {
		c[i] ^= y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re ^= c[i];
	}
	return re;
}
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	L[x] = ss;
	ss++;
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x);
		}
	}
	R[x] = ss;
}
int lca(int x, int y) {
	if (d[x] < d[y]) {
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 20; i++) {
		if (dd >> i & 1) {
			x = f[x][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 20 - 1; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		change(L[i], w[i]);
		change(R[i], w[i]);
	}
	for (int i = 0; i < q; i++) {
		int o, x, y;
		cin >> o >> x >> y;
		if (o == 1) {
			change(L[x], w[x] ^ y);
			change(R[x], w[x] ^ y);
			w[x] = y;
		} else {
			cout << (query(L[x]) ^ query(L[y]) ^ w[lca(x, y)]) << endl;
		}
	}
	return 0;
}