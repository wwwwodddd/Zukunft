#include <bits/stdc++.h>
using namespace std;
int f[1020];
int n, m;
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
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
	}
	sort(a, a + m);
	int cnt = n;
	for (int i = 0; i < m; i++) {
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y) {
			f[x] = y;
			cnt--;
			if (cnt == 1) {
				cout << a[i].first << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}