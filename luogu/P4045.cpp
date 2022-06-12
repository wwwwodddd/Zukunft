#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[102][26], tt;
long long f[30][102][1025];
int v[102];
int g[102];
int q[102], qq;
char c[102];
void ins(char *s, int u)
{
	int p = 0;
	for (; *s; s++)
	{
		if (t[p][*s - 'a'] == 0)
		{
			t[p][*s - 'a'] = ++tt;
		}
		p = t[p][*s - 'a'];
	}
	v[p] = u;
}
void dfs(int x, int y, int z)
{
	if (!f[x][y][z])
	{
		return;
	}
	if (x == m)
	{
		c[m] = 0;
		puts(c);
		return;
	}
	for (int k = 0; k < 26; k++)
	{
		c[x] = 'a' + k;
		dfs(x + 1, t[y][k], z | v[t[y][k]]);
	}
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", c);
		ins(c, 1 << i);
	}
	q[qq++] = 0;
	for (int j = 0; j < qq; j++)
	{
		int u = q[j];
		v[u] |= v[g[u]];
		for (int i = 0; i < 26; i++)
		{
			if (t[u][i])
			{
				g[t[u][i]] = u ? t[g[u]][i] : 0;
				q[qq++] = t[u][i];
			}
			else
			{
				t[u][i] = t[g[u]][i];
			}
		}
	}
	for (int j = 0; j <= tt; j++)
	{
		f[m][j][(1 << n) - 1] = 1;
	}
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = 0; j <= tt; j++)
		{
			for (int l = 0; l < 1 << n; l++)
			{
				for (int k = 0; k < 26; k++)
				{
					f[i][j][l] += f[i + 1][t[j][k]][l | v[t[j][k]]];
				}
			}
		}
	}
	printf("%lld\n", f[0][0][0]);
	if (f[0][0][0] <= 42)
	{
		dfs(0, 0, 0);	
	}
	return 0;
}
