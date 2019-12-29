#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 1e9;
vector<pair<int, int> > a[100020];
priority_queue<pair<int, int> > q;
int da[100020];
int db[100020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(da, 0x3f, sizeof da);
	da[1] = 0;
	q.push(make_pair(-da[1], 1));
	while (q.size() > 0) {
		pair<int, int> u = q.top();
		q.pop();
		if (-u.first > da[u.second]) {
			continue;
		}
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i];
			if (da[e.first] > da[u.second] + e.second) {
				da[e.first] = da[u.second] + e.second;
				q.push(make_pair(-da[e.first], e.first));
			}
		}
	}
	memset(db, 0x3f, sizeof db);
	db[n] = 0;
	q.push(make_pair(-db[n], n));
	while (q.size() > 0) {
		pair<int, int> u = q.top();
		q.pop();
		if (-u.first > db[u.second]) {
			continue;
		}
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i];
			if (db[e.first] > db[u.second] + e.second) {
				db[e.first] = db[u.second] + e.second;
				q.push(make_pair(-db[e.first], e.first));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (da[i] + a[i][j].second + db[a[i][j].first] > da[n]) {
				ans = min(ans, da[i] + a[i][j].second + db[a[i][j].first]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}