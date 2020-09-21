#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> a[16020];
int w[16020];
int f[16020];
void dfs(int x, int y) {
	f[x] = w[x];
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] != y) {
			dfs(a[x][i], x);
			f[x] += max(f[a[x][i]], 0);
		}
	}
	ans = max(ans, f[x]);
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
	ans = w[1];
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}