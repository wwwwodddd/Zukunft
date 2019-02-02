#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[200020];
int f[200020][18]; // father
int d[200020]; //depth
long long b[200020]; // 有多少条路径过自己父亲这条边
long long r[200020]; // 当前点有多少个lca
long long c[200020]; // 子树内有多少个lca
long long e[200020]; // 有多少个路径，以x的父亲节点为lca
long long ans;
map<pair<int, int>, int> g[200020];
void dfs(int x, int y) {
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
}

void dfs2(int x, int y) {
	long long u = c[x];
	r[x] = c[x];
	long long s1 = 0;
	long long s2 = 0;
	for (int i: a[x]) {
		if (i != y) {
			dfs2(i, x);
			c[x] += c[i];
			b[x] += b[i];
			s1 += c[i];
			s2 += c[i] * c[i];
			ans -= (b[i] - e[i]) * (b[i] - e[i] - 1) / 2;
		}
	}
	ans -= u * (m - c[x] - b[x]);
// 有一些会被减两次
	ans += (s1 * s1 - s2) / 2;
// 加回来


	ans -= (b[x] + r[x]) * (b[x] + r[x] - 1) / 2;
//  cerr << (b[x] + r[x]) * (b[x] + r[x] - 1) / 2 << endl;
// 减去交集为0的对数（过点x的）

	ans += (b[x]) * (b[x] - 1) / 2 * 2;
//  cerr << (b[x]) * (b[x] - 1) / 2 << endl;
// 加上交集为1的对数（过点x父亲那条边的）

// 减去交集为2的，LCA是当前点。
	for (pair<pair<int, int>, int> i: g[x]) {
		ans -= (long long)i.second * (i.second - 1) / 2;
//      cerr << (long long)i.second * (i.second - 1) / 2 << endl;
	}
// 接下来需要考虑的路径就是自己孩子到自己父亲节点这种路径了
// 简单来说这就是b[i] ?但是有一些路径以自己结束啊，再开一个数组吧。
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

/*
对于每个点，每条路径是一个大小为2的集合
问有多少对集合没有交集
交集为0的对数 - 交集为1的对数 + 交集为2的对数
*/

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	m -= n - 1;
	for (int i = 0; i < m; i++) {
		int x, y, nx, ny;
		scanf("%d%d", &x, &y);
		nx = x;
		ny = y;
		int l = lca(x, y);
		b[x]++;
		b[y]++;
		b[l] -= 2;
		c[l]++;
		for (int i = 17; i >= 0; i--) {
			if (d[f[nx][i]] > d[l]) {
				nx = f[nx][i];
			}
			if (d[f[ny][i]] > d[l]) {
				ny = f[ny][i];
			}
		}
		if (nx > ny) {
			swap(nx, ny);
		}
		if (nx != l) {
			e[nx]++;
		}
		if (ny != l) {
			e[ny]++;
		}
		if (nx != l && ny != l) {
			g[l][make_pair(nx, ny)]++;
		}
	}
	ans = (long long)m * (m - 1) / 2;
/*
全部 m*(m-1)/2
减去 不想交的
*/
	dfs2(1, 0);
/*
到这里，答案应该是点相交的无序对数量
还需要减去，只相交在点上的，也就是 -(交集为0的对数 - 交集为1的对数 + 交集为2的对数)
*/
	printf("%lld\n", ans);
	return 0;
}