#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[1520];
int f[1520];
int g[1520];
void dfs(int x, int y) {
	f[x] = 0;
	g[x] = 1;
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] != y) {
			dfs(a[x][i], x);
			f[x] += g[a[x][i]];
			g[x] += min(f[a[x][i]], g[a[x][i]]);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, k;
		cin >> x >> k;
		for (int j = 0; j < k; j++) {
			cin >> y;
			a[y].push_back(x);
			a[x].push_back(y);
		}
	}
	dfs(0, -1);
	cout << min(f[0], g[0]) << endl;
	return 0;
}