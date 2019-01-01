#include <bits/stdc++.h>
using namespace std;
int f[5020];
int n, m;
long long ans;
pair<int, pair<int, int> > a[200020];
int F(int x) {
	if (f[x] == x) {
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
		ans += a[i].first;
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++) {
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y) {
			f[x] = y;
			ans -= a[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}