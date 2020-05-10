#include <bits/stdc++.h>
using namespace std;
int n, lc;
long long r;
long long a[100020];
long long l[100020];
pair<int, int> f[100020];
pair<int, int> c[2][100020];
void R(int x, int y, pair<int, int> z) {
	for (; y <= n; y += y & -y) {
		c[x][y] = max(c[x][y], z);
	}
}
pair<int, int> G(int x, int y) {
	pair<int, int> u = {0, 0};
	for (; y > 0; y -= y & -y) {
		u = max(u, c[x][y]);
	}
	return u;
}
void dfs(int p) {
	if (p == 0) {
		return;
	}
	dfs(f[p].second);
	printf("%d ", p);
}
int main() {
	scanf("%d%lld", &n, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		l[lc++] = a[i];
	}
	sort(l, l + lc);
	lc = unique(l, l + lc) - l;
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(l, l + lc, a[i]) - l;
		int p0 = upper_bound(l, l + lc, a[i] - r) - l;
		int p1 = n - (lower_bound(l, l + lc, a[i] + r) - l);
		pair<int, int> u = max(G(0, p0), G(1, p1));
		u.first++;
		f[i] = u;
		u.second = i;
		R(0, p + 1, u);
		R(1, n - p, u);
	}
	int z = 0, p = -1;
	for (int i = 1; i <= n; i++) {
		if (z < f[i].first) {
			z = f[i].first;
			p = i;
		}
	}
	printf("%d\n", z);
	dfs(p);
	printf("\n");
	return 0;
}