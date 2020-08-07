#include <bits/stdc++.h>
using namespace std;
int n, m;
double s1[400020];
double s2[400020];
double ad[400020];
void build(int x, int l, int r) {
	if (l == r) {
		scanf("%lf", &s1[x]);
		s2[x] = s1[x] * s1[x];
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	s1[x] = s1[x * 2] + s1[x * 2 + 1];
	s2[x] = s2[x * 2] + s2[x * 2 + 1];
}
void add(int x, int l, int r, double v) {
	ad[x] += v;
	s2[x] += 2 * v * s1[x] + (r - l + 1) * v * v;
	s1[x] += (r - l + 1) * v;
}
void push(int x, int l, int r) {
	int mid = (l + r) / 2;
	add(x * 2, l, mid, ad[x]);
	add(x * 2 + 1, mid + 1, r, ad[x]);
	ad[x] = 0;
}
void change(int x, int l, int r, int L, int R, double v) {
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
	s1[x] = s1[x * 2] + s1[x * 2 + 1];
	s2[x] = s2[x * 2] + s2[x * 2 + 1];
}
double query(double s[], int x, int l, int r, int L, int R) {
	if (r < L || R < l) {
		return 0;
	}
	if (L <= l && r <= R) {
		return s[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return query(s, x * 2, l, mid, L, R) + query(s, x * 2 + 1, mid + 1, r, L, R);
}
int main() {
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		int o, x, y;
		double z;
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1) {
			scanf("%lf", &z);
			change(1, 1, n, x, y, z);
		} else {
			double z1 = query(s1, 1, 1, n, x, y) / (y - x + 1);
			if (o == 2) {
				printf("%.4f\n", z1);
			} else {
				double z2 = query(s2, 1, 1, n, x, y) / (y - x + 1);
				printf("%.4f\n", z2 - z1 * z1);
			}
		}
	}
	return 0;
}