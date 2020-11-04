#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, m, q;
long long mn[400020];
long long inf = 9223372036854775807LL;
void bd(int x, int l, int r) {
	if (l + 1 == r) {
		mn[x] = inf;
		return;
	}
	int m = (l + r) / 2;
	bd(x * 2, l, m);
	bd(x * 2 + 1, m, r);
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
void cg(int x, int l, int r, int p, long long v) {
	if (l + 1 == r) {
		mn[x] = v;
		return;
	}
	int m = (l + r) / 2;
	if (p < m) {
		cg(x * 2, l, m, p, v);
	} else {
		cg(x * 2 + 1, m, r, p, v);
	}
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
long long qy(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return mn[x];
	}
	if (R <= l || r <= L) {
		return inf;
	}
	int m = (l + r) / 2;
	return min(qy(x * 2, l, m, L, R), qy(x * 2 + 1, m, r, L, R));
}
vector<int> a[100020];
vector<pair<int, int> >b[100020];
long long f[100020];
void dfs(int x, int d) {
	if (x == 1) {
		f[x] = 0;
	} else {
		long long tmp = inf;
		for (int i = 0; i < b[x].size(); i++) {
			tmp = min(tmp, qy(1, 0, n, d - b[x][i].first, d) + b[x][i].second);
		}
		f[x] = tmp;
	}
	cg(1, 0, n, d, f[x]);
	for (int i = 0; i < a[x].size(); i++) {
		dfs(a[x][i], d + 1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	bd(1, 0, n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[y].push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int v, k, w;
		scanf("%d%d%d", &v, &k, &w);
		b[v].push_back(make_pair(k, w));
	}
	dfs(1, 0);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int x;
		scanf("%d", &x);
		printf("%lld\n", f[x]);
	}
	return 0;
}