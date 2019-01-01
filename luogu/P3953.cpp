#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
int d[100020];
int v[100020][51];
int f[100020][51];
vector<pair<int, int> > a[100020];
vector<pair<int, int> > b[100020];
set<pair<int, int> > s;
bool err;
int F(int x, int k) {
	if (v[x][k] == 1) {
		return f[x][k];
	}
	if (v[x][k] == 2) {
		err = true;
		return f[x][k];
	}
	v[x][k] = 2;
	for (int ii = 0; ii < b[x].size(); ii++) {
		pair<int, int> i = b[x][ii];
		int nk = d[x] + k - i.second - d[i.first];
		if (nk < 0) {
			continue;
		}
		f[x][k] = (f[x][k] + F(i.first, nk)) % p;
	}
	v[x][k] = 1;
	return f[x][k];
}
int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d%d%d", &n, &m, &k, &p);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			b[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[x].push_back(make_pair(y, z));
			b[y].push_back(make_pair(x, z));
		}
		memset(d, 0x3f, sizeof d);
		d[1] = 0;
		s.insert(make_pair(d[1], 1));
		while (s.size() > 0) {
			int u = s.begin()->second;
			s.erase(s.begin());
			for (int ii = 0; ii < a[u].size(); ii++) {
				pair<int, int> i = a[u][ii];
				if (d[i.first] > d[u] + i.second) {
					s.erase(make_pair(d[i.first], i.first));
					d[i.first] = d[u] + i.second;
					s.insert(make_pair(d[i.first], i.first));
				}
			}
		}
		err = false;
		int z = 0;
		memset(f, 0, sizeof f);
		memset(v, 0, sizeof v);
//		v[1][0] = 1;
		f[1][0] = 1;
		for (int i = 0; i <= k; i++) {
			z = (z + F(n, i)) % p;
		}
		if (err) {
			printf("-1\n");
		} else {
			printf("%d\n", z);
		}
	}
}