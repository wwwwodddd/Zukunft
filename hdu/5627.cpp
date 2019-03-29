#include <bits/stdc++.h>
using namespace std;
int t, n, m, ans;
vector<pair<int, int> > a[300020];
int v[300020];
int dfs(int x) {
	if (v[x]) {
		return 0;
	}
	v[x] = true;
	int re = 1;
	for (int i = 0; i < a[x].size(); i++) {
		if ((a[x][i].second & ans) == ans) {
			re += dfs(a[x][i].first);
		}
	}
	return re;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[x].push_back(make_pair(y, z));
			a[y].push_back(make_pair(x, z));
		}
		ans = 0;
		for (int i = 30; i >= 0; i--) {
			memset(v, 0, sizeof v);
			ans += 1 << i;
			if (dfs(1) < n) {
				ans -= 1 << i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}