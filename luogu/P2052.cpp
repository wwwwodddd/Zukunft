#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[1000020];
long long z;
int n;
int dfs(int x, int y) {
	int sz = 1;
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i].first != y) {
			int t = dfs(a[x][i].first, x);
			z += (long long)a[x][i].second * abs(n - 2 * t);
			sz += t;
		}
	}
	return sz;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(1, 0);
	printf("%lld\n", z);
	return 0;
}