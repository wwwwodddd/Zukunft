#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[300020];
int f[300020];
int s[300020];
int qq[300020], bb, ff;
multiset<int> ms[600020];
int mn[2400020];
int inf = 1e9;
void build(int x, int L, int R) {
	if (L == R - 1) {
		mn[x] = inf;
		return;
	}
	int M = (L + R) / 2;
	build(x * 2, L, M);
	build(x * 2 + 1, M, R);
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
int query(int x, int L, int R, int l, int r) {
	if (r <= L || R <= l) {
		return inf;
	}
	if (l <= L && R <= r) {
		return mn[x];
	}
	int M = (L + R) / 2;
	return min(query(x * 2, L, M, l, r), query(x * 2 + 1, M, R, l, r));
}
void insert(int x, int L, int R, int p, int v) {
	if (L == R - 1) {
		ms[L].insert(v);
		mn[x] = *ms[L].begin();
		return;
	}
	int M = (L + R) / 2;
	if (p < M) {
		insert(x * 2, L, M, p, v);
	} else {
		insert(x * 2 + 1, M, R, p, v);
	}
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
void erase(int x, int L, int R, int p, int v) {
	if (L == R - 1) {
		multiset<int>::iterator it = ms[L].find(v);
		assert(it != ms[L].end());
		ms[L].erase(it);
		if (ms[L].size() > 0) {
			mn[x] = *ms[L].begin();
		} else {
			mn[x] = inf;
		}
		return;
	}
	int M = (L + R) / 2;
	if (p < M) {
		erase(x * 2, L, M, p, v);
	} else {
		erase(x * 2 + 1, M, R, p, v);
	}
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", c);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + (c[i] == 'G');
	}
	qq[ff++] = 0;
	build(1, 0, 2 * n + 1);
	insert(1, 0, 2 * n + 1, n, 0);
	for (int i = 1; i <= n; i++) {
		while (qq[bb] < i - m) {
			bb++;
		}
		{
			int u = i - m - 1;
			if (u >= 0) {
				erase(1, 0, 2 * n + 1, n + u - 2 * s[u], f[u]);
			}
		}
		assert(bb < ff);
		f[i] = f[qq[bb]] + 1;
		int tmp = query(1, 0, 2 * n + 1, 0, n + i - 2 * s[i]);
		f[i] = min(f[i], tmp);
		insert(1, 0, 2 * n + 1, n + i - 2 * s[i], f[i]);
		while (bb < ff && f[qq[ff - 1]] >= f[i]) {
			ff--;
		}
		qq[ff++] = i;
/*
		for (int j = max(i - m, 0); j < i; j++) {
			if (i - 2 * s[i] > j - 2 * s[j]) {
				f[i] = min(f[i], f[j]);
			} else {
				f[i] = min(f[i], f[j] + 1);
			}
		}
*/
//		cerr << i << ' ' << f[i] << endl;
	}
	printf("%d\n", f[n]);
	return 0;
}