#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int d[100020];
vector<pair<int, int> > a[100020];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
	}
	memset(d, 0xc0, sizeof d);
	d[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			d[a[i][j].first] = max(d[a[i][j].first], d[i] + a[i][j].second);
		}
	}
	if (d[n] < 0) {
		cout << -1 << endl;
	} else {
		cout << d[n] << endl;
	}
	return 0;
}