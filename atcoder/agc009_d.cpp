#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<int> a[100020];
int dfs(int x, int y) {
	int c = 0, d = 0, p = 0;
	for (int i: a[x]) {
		if (i != y) {
			int u = dfs(i, x);
			d |= c & u;
			c |= u;
		}
	}
	while (1 << p < d || c >> p & 1) {
		p++;
	}
	return (c >> p | 1) << p;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	printf("%d\n", 31 - __builtin_clz(dfs(1, 0)));
	return 0;
}