#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[20020];
queue<int> q;
int d[20020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(d, -1, sizeof d);
	d[1] = 0;
	q.push(1);
	while (q.size() > 0) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < a[u].size(); i++) {
			int e = a[u][i];
			if (d[e] == -1) {
				d[e] = d[u] + 1;
				q.push(e);
			}
		}
	}
	int maxdis = -1;
	int maxindex = -1;
	int maxcnt = -1;
	for (int i = 1; i <= n; i++) {
		if (maxdis < d[i]) {
			maxdis = d[i];
			maxindex = i;
			maxcnt = 1;
		} else if (maxdis == d[i]) {
			maxcnt++;
		}
	}
	printf("%d %d %d\n", maxindex, maxdis, maxcnt);
	return 0;
}