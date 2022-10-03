#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020];
pair<int, int> mx[400020];
pair<int, int> bing(pair<int, int> p, pair<int, int> q) {
	int a[] = {p.first, p.second, q.first, q.second};
	sort(a, a + 4);
	return make_pair(a[3], a[2]);
}
void build(int x, int l, int r) {
	if (l == r) {
		mx[x] = make_pair(a[l], 0);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	mx[x] = bing(mx[x * 2], mx[x * 2 + 1]);
}
void change(int x, int l, int r, int p, int v) {
	if (l == r) {
		mx[x] = make_pair(v, 0);
		return;
	}
	int mid = (l + r) / 2;
	if (p > mid) {
		change(x * 2 + 1, mid + 1, r, p, v);
	} else {
		change(x * 2, l, mid, p, v);
	}
	mx[x] = bing(mx[x * 2], mx[x * 2 + 1]);
}
pair<int, int> query(int x, int l, int r, int L, int R) {
	if (r < L || R < l) {
		return make_pair(0, 0);
	}
	if (L <= l && r <= R) {
		return mx[x];
	}
	int mid = (l + r) / 2;
	return bing(query(x * 2, l, mid, L, R), query(x * 2 + 1, mid + 1, r, L, R));
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char o;
		int x, y;
		scanf(" %c%d%d", &o, &x, &y);
		if (o == 'Q') {
			pair<int, int> u = query(1, 1, n, x, y);
			printf("%d\n", u.first + u.second);
		} else {
			change(1, 1, n, x, y);
		}
	}
	return 0;
}
