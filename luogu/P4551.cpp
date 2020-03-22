#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[100020];
int f[100020];
int t[4000020][2], tt;
int n, m, x, y, z;
void dfs(int x, int y) {
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i].first != y) {
			f[a[x][i].first] = f[x] ^ a[x][i].second;
			dfs(a[x][i].first, x);
		}
	}
}
void insert(int x) {
	int p = 0;
	for (int i = 30; i >= 0; i--) {
		if (t[p][x >> i & 1] == 0) {
			t[p][x >> i & 1] = ++tt;
		}
		p = t[p][x >> i & 1];
	}
}
int query(int x) {
	int p = 0, re = 0;
	for (int i = 30; i >= 0; i--) {
		if (t[p][~x >> i & 1] > 0) {
			p = t[p][~x >> i & 1];
			re += 1 << i;
		} else {
			p = t[p][x >> i & 1];
		}
	}
	return re;
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		insert(f[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, query(f[i]));
	}
	cout << ans << endl;
	return 0;
}