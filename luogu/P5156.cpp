#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k, inf = 4e18;
int a[262147];
vector<int> b[262147];
pair<int, ll> t[262147];
int v[262147];
pair<int, ll> add(pair<int, ll> a, pair<int, ll> b) {
	if (a.first > b.first) {
		return a;
	} else if (a.first < b.first) {
		return b;
	} else {
		return make_pair(a.first, min(a.second + b.second, inf));
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
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	change(1, n + 1, 1, n + 1, make_pair(0, 1));
	for (int i = n; i > 0; i--) {
		pair<int, ll> res = query(1, n + 1, 1, a[i], n + 1);
		res.first++;
		change(1, n + 1, 1, a[i], res);
	}
	for (int i = 1; i <= n; i++) {
		pair<int, ll> res = query(1, n + 1, 1, i, i);
		b[res.first].push_back(i);
	}
	pair<int, ll> ans = query(1, n + 1, 1, 1, n + 1);
	int st = 1;
	int last = 0;
	assert(k <= ans.second);
	for (int i = ans.first; i > 0; i--) {
		for (int jj = b[i].size() - 1; jj >= 0; jj--) {
			int j = b[i][jj];
			pair<int, ll> res = query(1, n + 1, 1, j, j);
			if (k > res.second) {
				k -= res.second;
			} else {
				v[j] = 1;
				last = j;
				for (; a[st] != j; st++) {
					change(1, n + 1, 1, a[st], make_pair(0, 0));
				}
				break;
			}
		}
	}
	printf("%d\n", n - ans.first);
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			printf("%d\n", i);
		}
	}
	return 0;
}