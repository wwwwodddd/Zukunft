#include <bits/stdc++.h>
using namespace std;
int f[40020];
int n, m;
pair<int, pair<int, int> > a[100020];
int F(int x) {
	if (f[x] == x) {
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
	}
	sort(a, a + m);
	for (int i = m - 1; i >= 0; i--) {
		U(a[i].second.first, a[i].second.second + n);
		U(a[i].second.second, a[i].second.first + n);
		if (F(a[i].second.first) == F(a[i].second.first + n)) {
			cout << a[i].first << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}