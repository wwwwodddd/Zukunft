#include <bits/stdc++.h>
using namespace std;
vector<int> a[1020];
bool v[1020];
void dfs(int x) {
	v[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		if (!v[a[x][i]]) {
			dfs(a[x][i]);
		}
	}
}
int main() {
	int n, m, x, y;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cin >> m;
		for (int i = 1; i <= n; i++) {
			a[i].clear();
		}
		memset(v, 0, sizeof v);
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!v[i]) {
				ans++;
				dfs(i);
			}
		}
		printf("%d\n", ans - 1);
	}
}