#include <bits/stdc++.h>
using namespace std;
int n, m;
long long sm[800020];
long long ad[800020];
void build(int x, int l, int r) {
	if (l == r) {
		scanf("%lld", &sm[x]);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	sm[x] = sm[x * 2] + sm[x * 2 + 1];
}
void add(int x, int l, int r, long long v) {
	sm[x] += (r - l + 1) * v;
	ad[x] += v;
}
void push(int x, int l, int r) {
	int mid = (l + r) / 2;
	add(x * 2, l, mid, ad[x]);
	add(x * 2 + 1, mid + 1, r, ad[x]);
	ad[x] = 0;
}
void change(int x, int l, int r, int L, int R, long long v) {
	if (r < L || R < l) {
		return;
	}
	if (L <= l && r <= R) {
		add(x, l, r, v);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid + 1, r, L, R, v);
	sm[x] = sm[x * 2] + sm[x * 2 + 1];
}
long long query(int x, int l, int r, int L, int R) {
	if (r < L || R < l) {
		return 0;
	}
	if (L <= l && r <= R) {
		return sm[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid + 1, r, L, R);
}
int main() {
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		int o, x, y;
		long long z;
		scanf("%d", &o);
		if (o == 1) {
			scanf("%d%d%lld", &x, &y, &z);
			change(1, 1, n, x, y, z);
		} else if (o == 2 || o == 3) {
			scanf("%lld", &z);
			change(1, 1, n, 1, 1, o == 2 ? z : -z);
		} else if (o == 4) {
			scanf("%d%d", &x, &y);
			printf("%lld\n", query(1, 1, n, x, y));
		} else {
			printf("%lld\n", query(1, 1, n, 1, 1));
		}
	}
	return 0;
}
