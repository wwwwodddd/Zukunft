#include <bits/stdc++.h>
using namespace std;
const int mod = 80112002;
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
	for (int i: a[x]) {
		f[x] = (f[x] + F(i)) % mod;
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
		if (in[i] == 0) {
			ans = (ans + F(i)) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}