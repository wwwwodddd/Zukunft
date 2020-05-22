#include <bits/stdc++.h>
using namespace std;
int n, x, y, t;
vector<pair<int, int> > a[100020];
long long s[100020];
long long z[100020];
long long sum;
int dfs(int x, int y) {
	int sz = 1;
	for (pair<int, int> u: a[x]) {
		if (u.first == y) {
			continue;
		}
		int r = dfs(u.first, x);
		if (r * 2 != n) {
			z[u.second] = (s[u.first] - s[x]) / (n - r * 2);
			sum -= z[u.second] * r * (n - r) * 2;
		} else {
			t = u.second;
		}
		sz += r;
	}
	return sz;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, i));
		a[y].push_back(make_pair(x, i));
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);
		sum += s[i];
	}
	dfs(1, 0);
	if (t) {
		z[t] = sum * 2 / n / n;
	}
	for (int i = 1; i < n; i++) {
		printf("%lld\n", z[i]);
	}
	return 0;
}