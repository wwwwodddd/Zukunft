#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[100020];
bool v[100020];
int in[100020];
int f[100020];
int F(int x) {
	if (v[x]) {
		return f[x];
	}
	v[x] = true;
	f[x] = a[x].size() == 0;
	for (int i = 0; i < a[x].size(); i++) {
		f[x] += F(a[x][i]);
	}
	return f[x];
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
		if (in[i] == 0 && a[i].size() > 0) {
			ans += F(i);
		}
	}
	cout << ans << endl;
	return 0;
}