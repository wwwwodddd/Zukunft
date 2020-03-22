#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[100020];
bool v[100020];
int f[100020];
void dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		if (!v[a[x][i]]) {
			dfs(a[x][i]);
		}
		f[x] = max(f[x], f[a[x][i]]);
	}
	f[x]++;
	v[x] = true;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			dfs(i);
		}
		cout << f[i] << endl;
	}
	return 0;
}