#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100020];
int xx[100020];
int yy[100020];
int v[100020];
int maxx, minx;
int maxy, miny;
int ans;
void dfs(int x) {
	v[x] = true;
	maxx = max(maxx, xx[x]);
	minx = min(minx, xx[x]);
	maxy = max(maxy, yy[x]);
	miny = min(miny, yy[x]);
	for (int i: a[x]) {
		if (!v[i]) {
			dfs(i);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &xx[i], &yy[i]);
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	ans = 1e9;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			maxx = maxy = 0;
			minx = miny = 1e9;
			dfs(i);
			ans = min(ans, (maxx - minx + maxy - miny) * 2);
		}
	}
	printf("%d\n", ans);
	return 0;
}