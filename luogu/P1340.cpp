#include <bits/stdc++.h>
using namespace std;
int f[220];
int n, m;
vector<pair<int, pair<int, int> > > a;
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void mst()
{
	int ans = 0, c = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y)
		{
			a[c++] = a[i];
			f[x] = y;
			ans += a[i].first;
		}
	}
	a.resize(c);
	if (c < n - 1)
	{
		ans = -1;
	}
	cout << ans << endl;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		pair<int, pair<int, int> > u;
		cin >> u.second.first >> u.second.second >> u.first;
		a.push_back(u);
		mst();
	}
	return 0;
}
