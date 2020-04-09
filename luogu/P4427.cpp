#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
vector<int> a[300020];
int f[300020][20];
int s[300020][52];
int d[300020];
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x);
		}
	}
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
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		s[i][0] = 1;
		for (int j = 1; j <= 50; j++)
		{
			s[i][j] = (long long)s[i][j - 1] * i % mod;
		}
	}
	for (int j = 1; j <= 50; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			s[i][j] = (s[i][j] + s[i - 1][j]) % mod;
		}
	}
	dfs(1, 0);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int l = lca(x, y);
		int ans = ((long long)s[d[x] - 1][z] + s[d[y] - 1][z] + 2 * mod - s[d[l] - 1][z] - s[max(d[l] - 2, 0)][z]) % mod;
		printf("%d\n", ans);
	}
	return 0;
}