#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<tuple<int, int, int> > a[200020];
set<pair<long long, int> > q;
long long d[200020];
int p[200020]; 
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_tuple(y, z, i));
		a[y].push_back(make_tuple(x, z, i));
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	q.insert(make_pair(d[1], 1));
	while (q.size() > 0) {
		pair<int, int> u = *q.begin();
		q.erase(q.begin());
		for (auto e : a[u.second]) {
			if (d[get<0>(e)] > d[u.second] + get<1>(e)) {
				q.erase(make_pair(d[get<0>(e)], get<0>(e)));
				d[get<0>(e)] = d[u.second] + get<1>(e);
				p[get<0>(e)] = get<2>(e);
				q.insert(make_pair(d[get<0>(e)], get<0>(e)));
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		printf("%d%c", p[i], i == n ? '\n' : ' ');
	}
	return 0;
}
