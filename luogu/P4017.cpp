#include <bits/stdc++.h>
using namespace std;
const int mod = 80112002;
int n, m, x, y;
vector<int> a[100020];
bool v[100020];
int in[100020];
int f[100020];
void dfs(int x) {
	if (a[x].size() == 0) {
		f[x] = 1;
	}
	for (int i = 0; i < a[x].size(); i++) {
		if (!v[a[x][i]]) {
			dfs(a[x][i]);
		}
		f[x] = (f[x] + f[a[x][i]]) % mod;
	}
	v[x] = true;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x].push_back(y);
		in[y]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			dfs(i);
		}
		if (in[i] == 0) {
			ans = (ans + f[i]) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}