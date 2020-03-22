#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[6020];
int w[6020];
int f[6020];
int g[6020];
void dfs(int x, int y) {
	f[x] = 0;
	g[x] = w[x];
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] != y) {
			dfs(a[x][i], x);
			f[x] += max(f[a[x][i]], g[a[x][i]]);
			g[x] += f[a[x][i]];
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[y].push_back(x);
		a[x].push_back(y);
	}
	dfs(1, 0);
	cout << max(f[1], g[1]) << endl;
	return 0;
}