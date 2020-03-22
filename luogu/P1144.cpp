#include <bits/stdc++.h>
using namespace std;
int n, m, mod = 100003;
vector<int> a[1000020];
queue<int> q;
int d[1000020];
int f[1000020];
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
	f[1] = 1;
	q.push(1);
	while (q.size() > 0) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < a[u].size(); i++) {
			int e = a[u][i];
			if (d[e] == -1) {
				d[e] = d[u] + 1;
				f[e] = f[u];
				q.push(e);
			} else if (d[e] == d[u] + 1) {
				f[e] = (f[e] + f[u]) % mod;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", f[i]);
	}
	return 0;
}