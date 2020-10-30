#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100020];
vector<int> b[100020];
int deg[100020];
int in[100020];
int f[100020][18];
int d[100020];
int L[100020];
int R[100020];
int s[100020], ss;
int v[100020];
int c[100020];
void dfs(int x, int y) {
	L[x] = ss;
	s[ss++] = x;
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 18; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x);
		}
	}
	R[x] = ss;
}

int lca(int x, int y) {
	if (d[x] < d[y]) {
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 18; i++) {
		if (dd >> i & 1) {
			x = f[x][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 17; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

bool ok() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] <= 1 && in[i] == 0 && v[i] == 0) {
			q.push(i);
			v[i] = 1;
		}
	}
	int cnt = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		cnt++;
		for (int i: a[u]) {
			deg[i]--;
			if (deg[i] <= 1 && in[i] == 0 && v[i] == 0) {
				q.push(i);
				v[i] = 1;
			}
		}
		for (int i: b[u]) {
			in[i]--;
			if (deg[i] <= 1 && in[i] == 0 && v[i] == 0) {
				q.push(i);
				v[i] = 1;
			}
		}
	}
	return cnt == n;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		deg[x]++;
		deg[y]++;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		b[x].push_back(y);
		in[y]++;
		int l = lca(x, y);
		if (l == x) {
			c[0]++;
			c[n]--;
			if (l == y) {
				continue;
			}
			for (int i = 17; i >= 0; i--) {
				if (d[f[y][i]] > d[x]) {
					y = f[y][i];
				}
			}
			c[L[y]]--;
			c[R[y]]++;
		} else {
			c[L[x]]++;
			c[R[x]]--;
		}
	}

	if (!ok()) {
		for (int i = 1; i <= n; i++) {
			printf("0\n");
		}
		return 0;
	}

	for (int i = 0; i < n; i++) {
		c[i + 1] += c[i];
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", c[L[i]] == 0);
	}
	return 0;
}