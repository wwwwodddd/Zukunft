#include <bits/stdc++.h>
using namespace std;
int n, m, b;
vector<pair<int, int> > a[100020];
priority_queue<pair<int, int> > q;
int d[100020];
int f[100020];
bool ok(int x)
{
	if (f[1] > x || f[n] > x) {
		return false;
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	q.push(make_pair(-d[1], 1));
	while (q.size() > 0) {
		pair<int, int> u = q.top();
		q.pop();
		if (-u.first > d[u.second] || f[u.second] > x) {
			continue;
		}
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i];
			if (d[e.first] > d[u.second] + e.second) {
				d[e.first] = d[u.second] + e.second;
				q.push(make_pair(-d[e.first], e.first));
			}
		}
	}
	return d[n] <= b;
}
int main() {
	scanf("%d%d%d", &n, &m, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	int L = max(f[1], f[n]) - 1, R = 1e9 + 7;
	while (L < R - 1) {
		int M = (L + R) / 2;
		if (ok(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	if (R == 1e9 + 7) {
		printf("AFK\n");
	} else {
		printf("%d\n", R);
	}
	return 0;
}