#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int a[220], b[220], ac, bc, l[220];
bool g[220][220], v[220];
map<int, int> q;
bool P(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
bool dfs(int x) {
	for (int i = 0; i < bc; i++) {
		if (g[x][i] && !v[i]) {
			v[i] = true;
			if (l[i] == -1 || dfs(l[i])) {
				return l[i] = x, true;
			}
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		q[x] ^= 1;
		q[x + 1] ^= 1;
	}
	for (pair<int, int> i: q) {
		if (i.second == 0) {
			continue;
		}
		if (i.first & 1) {
			a[ac++] = i.first;
		} else {
			b[bc++] = i.first;
		}
	}
	for (int i = 0; i < ac; i++) {
		for (int j = 0; j < bc; j++) {
			if (P(abs(a[i] - b[j]))) {
				g[i][j] = true;
			}
		}
	}
	memset(l, -1, sizeof l);
	for (int i = 0; i < ac; i++) {
		memset(v, 0, sizeof v);
		if (dfs(i)) {
			z++;
		}
	}
	if ((ac - z) & 1) {
		z--;
	}
	printf("%d\n", ac + bc - z);
	return 0;
}