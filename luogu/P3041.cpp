#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[320][26], tt;
int f[1020][320];
int v[320];
int g[320];
int q[320], qq;
char c[20];
void ins(char *s)
{
	int p = 0;
	for (; *s; s++)
	{
		if (t[p][*s - 'A'] == 0)
		{
			t[p][*s - 'A'] = ++tt;
		}
		p = t[p][*s - 'A'];
	}
	v[p]++;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", c);
		ins(c);
	}
	q[qq++] = 0;
	for (int j = 0; j < qq; j++)
	{
		int u = q[j];
		v[u] += v[g[u]];
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
	memset(f, 0xc0, sizeof f);
	f[0][0] = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= tt; j++)
		{
			for (int k = 0; k < 26; k++)
			{
				f[i + 1][t[j][k]] = max(f[i + 1][t[j][k]], f[i][j] + v[t[j][k]]);
			}
		}
	}
	int z = 0;
	for (int j = 0; j <= tt; j++)
	{
		z = max(z, f[m][j]);
	}
	printf("%d\n", z);
	return 0;
}