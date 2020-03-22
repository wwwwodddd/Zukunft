#include <bits/stdc++.h>
using namespace std;
int n, m, s, ans;
vector<pair<int, int> > a[100020];
vector<pair<int, int> > b[100020];
priority_queue<pair<int, int> > q;
int da[100020];
int db[100020];
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		b[y].push_back(make_pair(x, z));
	}
	memset(da, 0x3f, sizeof da);
	da[s] = 0;
	q.push(make_pair(-da[s], s));
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
	db[s] = 0;
	q.push(make_pair(-db[s], s));
	while (q.size() > 0) {
		pair<int, int> u = q.top();
		q.pop();
		if (-u.first > db[u.second]) {
			continue;
		}
		for (int i = 0; i < b[u.second].size(); i++) {
			pair<int, int> e = b[u.second][i];
			if (db[e.first] > db[u.second] + e.second) {
				db[e.first] = db[u.second] + e.second;
				q.push(make_pair(-db[e.first], e.first));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, da[i] + db[i]);
	}
	printf("%d\n", ans);
	return 0;
}