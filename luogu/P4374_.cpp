#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > a[500020];
set<pair<int, int> > s[500020];
int z[500020];
void merge(int x, int y) {
	if (s[x].size() < s[y].size()) {
		s[x].swap(s[y]);
	}
	for (pair<int, int> i: s[y]) {
		if (s[x].find(i) != s[x].end()) {
			s[x].erase(i);
		} else {
			s[x].insert(i);
		}
	}
	s[y].clear();
}
void dfs(int x, int y) {
	for (pair<int, int> i: a[x]) {
		if (i.first != y) {
			dfs(i.first, x);
			z[i.second] = s[i.first].size() > 0 ? s[i.first].begin()->first : -1;
			merge(x, i.first);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, i));
		a[y].push_back(make_pair(x, i));
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		s[x].insert(make_pair(z, i));
		s[y].insert(make_pair(z, i));
	}
	dfs(1, 0);
	for (int i = 1; i < n; i++) {
		printf("%d\n", z[i]);
	}
	return 0;
}