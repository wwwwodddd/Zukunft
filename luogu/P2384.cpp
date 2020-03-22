#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > a[100020];
priority_queue<pair<double, int> > q;
double d[100020];
int f[100020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1e30;
		f[i] = -1;
	}
	d[1] = 0;
	f[1] = 1;
	q.push(make_pair(-d[1], 1));
	while (q.size() > 0) {
		pair<double, int> u = q.top();
		q.pop();
		if (-u.first > d[u.second]) {
			continue;
		}
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i];
			if (d[e.first] > d[u.second] + log(e.second)) {
				d[e.first] = d[u.second] + log(e.second);
				f[e.first] = f[u.second] * e.second % 9987;
				q.push(make_pair(-d[e.first], e.first));
			}
		}
	}
	printf("%d\n", f[n]);
	return 0;
}