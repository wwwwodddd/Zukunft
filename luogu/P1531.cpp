#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
int mx[800020];
void build(int x, int l, int r) {
	if (l == r) {
		mx[x] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}
void change(int x, int l, int r, int p, int v) {
	if (l == r) {
		mx[x] = v;
		return;
	}
	int mid = (l + r) / 2;
	if (p > mid) {
		change(x * 2 + 1, mid + 1, r, p, v);
	} else {
		change(x * 2, l, mid, p, v);
	}
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}
int query(int x, int l, int r, int L, int R) {
	if (r < L || R < l) {
		return 0;
	}
	if (L <= l && r <= R) {
		return mx[x];
	}
	int mid = (l + r) / 2;
	return max(query(x * 2, l, mid, L, R), query(x * 2 + 1, mid + 1, r, L, R));
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		char o;
		int x, y;
		scanf(" %c%d%d", &o, &x, &y);
		if (o == 'Q') {
			printf("%d\n", query(1, 1, n, x, y));
		} else {
			if (query(1, 1, n, x, x) < y) {
				change(1, 1, n, x, y);
			}
		}
	}
	return 0;
}