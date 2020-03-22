#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<pair<int, double> > a[100020];
priority_queue<pair<double, int> > q;
double d[100020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, -log(1 - z/100.)));
		a[y].push_back(make_pair(x, -log(1 - z/100.)));
	}
	scanf("%d%d", &s, &t);
	for (int i = 1; i <= n; i++) {
		d[i] = 1e30;
	}
	d[s] = 0;
	q.push(make_pair(-d[s], s));
	while (q.size() > 0) {
		pair<double, int> u = q.top();
		q.pop();
		if (-u.first > d[u.second]) {
			continue;
		}
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, double> e = a[u.second][i];
			if (d[e.first] > d[u.second] + e.second) {
				d[e.first] = d[u.second] + e.second;
				q.push(make_pair(-d[e.first], e.first));
			}
		}
	}
	printf("%.8f\n", exp(d[t]) * 100);
	return 0;
}