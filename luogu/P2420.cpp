#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[100020];
int f[100020];
int n, m, x, y, z;
void dfs(int x, int y) {
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i].first != y) {
			f[a[x][i].first] = f[x] ^ a[x][i].second;
			dfs(a[x][i].first, x);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(1, 0);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << (f[x] ^ f[y]) << endl;
	}
	return 0;
}