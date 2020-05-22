#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m, x, y, z;
vector<pair<int, int> > a[2020];
vector<int> b[2020];
vector<int> c[2020];
int d[2020], w[4020];
int st[2020], ed[2020];
bool v[2020];
bool dfs(int x, int y, int t, vector<int> &b) {
	if (x == t) {
		return true;
	}
	for (auto i: a[x]) {
		if (i.X != y) {
			b.push_back(i.Y);
			if (dfs(i.X, x, t, b)) {
				return true;
			}
			b.pop_back();
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[x].push_back({y, 2 * i});
		a[y].push_back({x, 2 * i + 1});
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &st[i], &ed[i]);
		dfs(st[i], 0, ed[i], b[i]);
		assert(b[i].size() > 0);
		for (int j: b[i]) {
			c[j / 2].push_back(i);
			d[j / 2]++;
		}
	}
	for (int i = 1; i < n; i++) {
		z += min(d[i], 2);
	}
	while (true) {
		int p = 0, q = -1; // p = choose edge, q = choose path
		for (int i = 1; i < n; i++) {
			if (d[i] == 1 && w[i * 2] != w[i * 2 + 1]) {
				p = i;
				break;
			}
		}
		if (p == 0) {
			for (int i = 1; i < n; i++) {
				if (d[i] >= 2) {
					p = i;
					break;
				}
			}
		}
		if (p == 0) {
			break;
		}
		for (int i: c[p]) {
			if (!v[i]) {
				q = i;
				break;
			}
		}
		assert(q >= 0);
		bool rev = false;
		v[q] = true;
		for (int i: b[q]) {
			if (i / 2 == p) {
				if (w[i]) {
					swap(st[q], ed[q]);
					for (int &j: b[q]) {
						j ^= 1;
					}
				}
				for (int &j: b[q]) {
					d[j / 2]--;
					w[j] = 1;
				}
				break;
			}
		}
	}
	printf("%d\n", z);
	for (int i = 0; i < m; i++) {
		printf("%d %d\n", st[i], ed[i]);
	}
	return 0;
}