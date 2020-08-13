#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<pair<int, int> > a[100020];
bool v[100020];
double f[100020];
double F(int x) {
	if (v[x]) {
		return f[x];
	}
	v[x] = true;
	if (a[x].size() == 0) {
		return 0;
	}
	for (int i = 0; i < a[x].size(); i++) {
		f[x] += F(a[x][i].first) + a[x][i].second;
	}
	f[x] /= a[x].size();
	return f[x];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
	}
	printf("%.2f\n", F(1));
	return 0;
}