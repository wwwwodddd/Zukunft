#include <bits/stdc++.h>
using namespace std;
int f[100020];
int n, m, l;
long long ans;
pair<int, pair<int, int> > a[100020];
int F(int x) {
	if (f[x] == x) {
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
}
int main() {
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
	}
	sort(a, a + m);
	for (int i = m - 1; i >= 0 && l > 0; i--) {
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y) {
			l--;
			f[x] = y;
			ans += a[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}