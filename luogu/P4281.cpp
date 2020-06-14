#include <bits/stdc++.h>
using namespace std;
void read(int&x) 
{
	char ch;
	while((ch=getchar())&&(ch<'0'||ch>'9'));
		x=ch-'0';
	while((ch=getchar())&&ch>='0'&&ch<='9')
		x=x*10+ch-'0';
}
int n, m;
int f[500020][20];
int d[500020];
struct Edge {
	int next;
	int to;
} e[1000020];
int h[500020], tot;
void add(int x, int y) {
	tot++;
	e[tot].next = h[x];
	e[tot].to = y;
	h[x] = tot;
}
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int ii = h[x]; ii > 0; ii = e[ii].next) {
		int i = e[ii].to;
		if (i != y) {
			dfs(i, x);
		}
	}
}
int lca(int x, int y) {
	if (d[x] < d[y]) {
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 20; i++) {
		if (dd >> i & 1) {
			x = f[x][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 20 - 1; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main() {
	read(n);
	read(m);
	// scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		read(x);
		read(y);
		// scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		read(a);
		read(b);
		read(c);
		// scanf("%d%d%d", &a, &b, &c);
		int x = lca(a, b);
		int y = lca(b, c);
		int z = lca(c, a);
		printf("%d %d\n", x ^ y ^ z, d[a] + d[b] + d[c] - d[x] - d[y] - d[z]);
	}
	return 0;
}