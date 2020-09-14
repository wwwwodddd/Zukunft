#include <bits/stdc++.h>
using namespace std;
int n, m;
int sm[400020];
int ad[400020];
void build(int x, int l, int r) {
	if (l == r) {
		sm[x] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	sm[x] = sm[x * 2] + sm[x * 2 + 1];
}
void add(int x, int l, int r) {
	sm[x] = (r - l + 1) - sm[x];
	ad[x] ^= 1;
}
void push(int x, int l, int r) {
	int mid = (l + r) / 2;
	if (ad[x])
	{
		add(x * 2, l, mid);
		add(x * 2 + 1, mid + 1, r);
		ad[x] = 0;
	}
}
void change(int x, int l, int r, int L, int R) {
	if (r < L || R < l) {
		return;
	}
	if (L <= l && r <= R) {
		add(x, l, r);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R);
	change(x * 2 + 1, mid + 1, r, L, R);
	sm[x] = sm[x * 2] + sm[x * 2 + 1];
}
int query(int x, int l, int r, int L, int R) {
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
		scanf("%d%d%d", &o, &x, &y);
		if (o == 0) {
			change(1, 1, n, x, y);
		} else {
			printf("%d\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}