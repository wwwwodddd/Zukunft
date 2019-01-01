#include <bits/stdc++.h>
using namespace std;
int f[10020];
int w[10020];
int n, m;
int ans;
pair<int, pair<int, int> > a[100020];
int F(int x) {
	if (f[x] == x) {
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
}
int main() {
	cin >> n >> m;
	ans = 1e9;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		cin >> w[i];
		ans = min(ans, w[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
		a[i].first *= 2;
		a[i].first += w[a[i].second.first];
		a[i].first += w[a[i].second.second];
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++) {
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y) {
			f[x] = y;
			ans += a[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}