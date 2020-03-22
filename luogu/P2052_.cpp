#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int next;
	int to;
	int length;
} e[2000020];
int h[1000020], tot;
long long z;
int n;
void add(int x, int y, int z) {
	tot++;
	e[tot].next = h[x];
	e[tot].to = y;
	e[tot].length = z;
	h[x] = tot;
}
int dfs(int x, int y) {
	int sz = 1;
	for (int i = h[x]; i > 0; i = e[i].next) {
		if (e[i].to != y) {
			int t = dfs(e[i].to, x);
			z += (long long)e[i].length * abs(n - 2 * t);
			sz += t;
		}
	}
	return sz;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs(1, 0);
	printf("%lld\n", z);
	return 0;
}