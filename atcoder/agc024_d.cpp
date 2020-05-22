#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x[120], y[120], c[120];
vector<int> a[120];
pair<ll, ll> z;
void dfs(int x, int y, int d) {
	int s = 0;
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x, d + 1);
			s++;
		}
	}
	c[d] = max(c[d], s);
}
void upd() {
	ll u = 0, v = 1;
	while (c[u]) {
		v *= c[u++];
	}
	z = min(z, {u, v});
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		a[x[i]].push_back(y[i]);
		a[y[i]].push_back(x[i]);
	}
	z = {n + 1, 0};
	for (int i = 1; i <= n; i++) {
		memset(c, 0, sizeof c);
		c[0] = 1;
		dfs(i, 0, 1);
		upd();
	}
	for (int i = 1; i < n; i++) {
		memset(c, 0, sizeof c);
		c[0] = 2;
		dfs(x[i], y[i], 1);
		dfs(y[i], x[i], 1);
		upd();
	}
	printf("%lld %lld\n", z.first, z.second);
	return 0;
}