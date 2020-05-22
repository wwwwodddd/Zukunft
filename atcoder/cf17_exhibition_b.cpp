#include <bits/stdc++.h>
using namespace std;
int n, a[200020], b[200020], bc;
int mn[800020];
int ad[800020];
void build(int x, int l, int r) {
	if (l + 1 == r) {
		mn[x] = b[l];
		return;
	}
	int m = (l + r) / 2;
	build(x * 2 + 1, l, m);
	build(x * 2 + 2, m, r);
	mn[x] = min(mn[x * 2 + 1], mn[x * 2 + 2]);
	return;
}
void push(int x) {
	mn[x * 2 + 1] += ad[x];
	mn[x * 2 + 2] += ad[x];
	ad[x * 2 + 1] += ad[x];
	ad[x * 2 + 2] += ad[x];
	ad[x] = 0;
}
void change(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		mn[x]++;
		ad[x]++;
		return;
	}
	if (r <= L || R <= l) {
		return;
	}
	push(x);
	int m = (l + r) / 2;
	change(x * 2 + 1, l, m, L, R);
	change(x * 2 + 2, m, r, L, R);
	mn[x] = min(mn[x * 2 + 1], mn[x * 2 + 2]);
}
int query(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return mn[x];
	}
	if (r <= L || R <= l) {
		return 2e9;
	}
	push(x);
	int m = (l + r) / 2;
	return min(query(x * 2 + 1, l, m, L, R), query(x * 2 + 2, m, r, L, R));
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	bc = unique(b, b + n) - b;
	build(0, 0, bc);
	long long z = 0;
	for (int i = 0; i < n; i++) {
		int p = lower_bound(b, b + bc, a[i]) - b;
		z += query(0, 0, bc, p, bc) - a[i];
		change(0, 0, bc, 0, p);
	}
	printf("%lld\n", z);
	return 0;
}