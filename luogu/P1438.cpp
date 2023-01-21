#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100020];
long long ad[400020];
long long df[400020];
void build(int x, int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
}
void zuo(int x, int l, int r, long long add, long long dif) {
	ad[x] += add;
	df[x] += dif;
}
void push(int x, int l, int r) {
	int mid = (l + r) / 2;
	zuo(x * 2, l, mid, ad[x], df[x]);
	zuo(x * 2 + 1, mid + 1, r, ad[x], df[x]);
	ad[x] = 0;
	df[x] = 0;
}
void change(int x, int l, int r, int L, int R, long long add, long long dif) {
	if (r < L || R < l) {
		return;
	}
	if (L <= l && r <= R) {
		zuo(x, l, r, add, dif);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, add, dif);
	change(x * 2 + 1, mid + 1, r, L, R, add, dif);
}
long long query(int x, int l, int r, int p) {
	if (l == r) {
		return a[l] + ad[x] + df[x] * l;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	if (p > mid) {
		return query(x * 2 + 1, mid + 1, r, p);
	} else {
		return query(x * 2, l, mid, p);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		int o, x, y;
		long long add, dif;
		scanf("%d", &o);
		if (o == 1) {
			scanf("%d%d%lld%lld", &x, &y, &add, &dif);
			add -= x * dif;
			change(1, 1, n, x, y, add, dif);
		} else {
			scanf("%d", &x);
			printf("%lld\n", query(1, 1, n, x));
		}
	}
	return 0;
}
