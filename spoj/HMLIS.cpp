#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int n;
int a[262147];
int b[262147];
pair<int, ll> t[262147];
pair<int, ll> add(pair<int, ll> a, pair<int, ll> b) {
	if (a.first > b.first) {
		return a;
	} else if (a.first < b.first) {
		return b;
	} else {
		return make_pair(a.first, (a.second + b.second) % mod);
	}
}

pair<int, ll> query(int l, int r, int x, int L, int R) {
	if (r < L || R < l) {
		return make_pair(-1, 0);
	}
	if (L <= l && r <= R) {
		return t[x];
	}
	int m = (l + r) / 2;
	return add(query(l, m, x * 2, L, R), query(m + 1, r, x * 2 + 1, L, R));
}

void change(int l, int r, int x, int p, pair<int, ll> w) {
	if (l == r) {
		t[x] = w;
		return;
	}
	int m = (l + r) / 2;
	if (p <= m) {
		change(l, m, x * 2, p, w);
	} else {
		change(m + 1, r, x * 2 + 1, p, w);
	}
	t[x] = add(t[x * 2], t[x * 2 + 1]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = i;
	}
	sort(b + 1, b + n + 1, [](int x, int y){return a[x] < a[y] || a[x] == a[y] && x > y;});
	change(1, n + 1, 1, n + 1, make_pair(0, 1));
	for (int i = n; i > 0; i--) {
		pair<int, ll> res = query(1, n + 1, 1, b[i], n + 1);
		res.first++;
		change(1, n + 1, 1, b[i], res);
	}
	pair<int, ll> ans = query(1, n + 1, 1, 1, n + 1);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}