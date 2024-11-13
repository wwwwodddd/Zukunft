#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
vector<int> a[100020];
int f[100020][101][2][2];
int g[101][2][2];
int s[100020];
//  f[i][j][2][2] 点 i 的子树，内部放了 j 个监听设备 问方案数
//  点i 放没放监听设备
//  点i 是否被监听了
inline void inc(int &re, int x, long long y)
{
	re = (re + x * y) % p;
}
void dfs(int x, int y)
{
	f[x][0][0][0] = 1;
	f[x][1][1][0] = 1;
	s[x] = 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			memset(g, 0, sizeof g);
			for (int j = min(m, s[x]); j >= 0; j--)
			{
				for (int k = min(m, s[i]); k >= 0; k--)
				{
					inc(g[j + k][0][0], f[x][j][0][0], f[i][k][0][1]);

					inc(g[j + k][0][1], f[x][j][0][0], f[i][k][1][1]);
					inc(g[j + k][0][1], f[x][j][0][1], f[i][k][0][1] + f[i][k][1][1]);

					inc(g[j + k][1][0], f[x][j][1][0], f[i][k][0][0] + f[i][k][0][1]);

					inc(g[j + k][1][1], f[x][j][1][0], f[i][k][1][0] + f[i][k][1][1]);
					inc(g[j + k][1][1], f[x][j][1][1], (long long)f[i][k][0][0] + f[i][k][0][1] + f[i][k][1][0] + f[i][k][1][1]);
				}
			}
			for (int j = 0; j <= m; j++)
			{
				f[x][j][0][0] = g[j][0][0];
				f[x][j][0][1] = g[j][0][1];
				f[x][j][1][0] = g[j][1][0];
				f[x][j][1][1] = g[j][1][1];
			}
			s[x] += s[i];
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", (f[1][m][0][1] + f[1][m][1][1]) % p);
	return 0;
}