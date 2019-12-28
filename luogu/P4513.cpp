#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node{
	int sm, lm, rm, mx;
	Node(int sm=0, int lm=0, int rm=0, int mx=0): sm(sm), lm(lm), rm(rm), mx(mx) {
	}
}t[1048577];
int a[500020];
Node operator+(const Node&a, const Node&b) {
	return Node(a.sm+b.sm, max(a.lm, a.sm+b.lm), max(a.rm+b.sm, b.rm), max(a.rm+b.lm, max(a.mx, b.mx)));
}
void build(int x, int l, int r) {
	if (l == r) {
		t[x] = Node(a[l], a[l], a[l], a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	t[x] = t[x * 2] + t[x * 2 + 1];
}
void change(int x, int l, int r, int p, int v) {
	if (l == r) {
		t[x] = Node(v, v, v, v);
		return;
	}
	int mid = (l + r) / 2;
	if (p > mid) {
		change(2 * x + 1, mid + 1, r, p, v);
	} else {
		change(2 * x, l, mid, p, v);
	}
	t[x] = t[x * 2] + t[x * 2 + 1];
}
Node query(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return t[x];
	}
	int mid = (l + r) / 2;
	if (R <= mid) {
		return query(x * 2, l, mid, L, R);
	}
	if (L > mid) {
		return query(x * 2 + 1, mid + 1, r, L, R);
	}
	return query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid + 1, r, L, R);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		int o, x, y;
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1) {
			if (x > y) {
				swap(x, y);
			}
			printf("%d\n", query(1, 1, n, x, y).mx);
		} else {
			change(1, 1, n, x, y);
		}
	}
	return 0;
}