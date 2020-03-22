#include <bits/stdc++.h>
using namespace std;
const int mod = 80112002;
int n, m, x, y, z;
vector<pair<int, int> > a[100020];
bool v[100020];
double f[100020];
void dfs(int x) {
	if (a[x].size() == 0) {
		f[x] = 0;
		return;
	}
	for (int i = 0; i < a[x].size(); i++) {
		if (!v[a[x][i].first]) {
			dfs(a[x][i].first);
		}
		f[x] += f[a[x][i].first] + a[x][i].second;
	}
	f[x] /= a[x].size();
	v[x] = true;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
	}
	dfs(1);
	printf("%.2f\n", f[1]);
	return 0;
}