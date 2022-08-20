#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[100020];
int f[100020];
int v[100020];
int n, m, q, x, y, z;
void dfs(int x) {
	v[x] = 1;
	for (int i = 0; i < a[x].size(); i++) {
		if (!v[a[x][i].first]) {
			f[a[x][i].first] = f[x] ^ a[x][i].second;
			dfs(a[x][i].first);
		}
	}
}
int main() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(1);
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		cout << (f[x] ^ f[y]) << endl;
	}
	return 0;
}
