#include <bits/stdc++.h>
using namespace std;
vector<int> a[5020];
int v[5020], ans;
void dfs(int x) {
	v[x] = ans;
	for (int i = 0; i < a[x].size(); i++) {
		if (!v[a[x][i]]) {
			dfs(a[x][i]);
		}
	}
}
int main() {
	int n, m, q, x, y;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			ans++;
			dfs(i);
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		if (v[x] == v[y]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}