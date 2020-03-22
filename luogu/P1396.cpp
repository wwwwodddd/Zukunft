#include <bits/stdc++.h>
using namespace std;
int f[10020];
int n, m, s, t;
long long ans;
pair<int, pair<int, int> > a[20020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++) {
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		f[x] = y;
		if (F(s) == F(t))
		{
			cout << a[i].first << endl;
			break;
		}
	}
	return 0;
}