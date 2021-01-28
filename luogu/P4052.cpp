#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
int n, m;
int t[6020][26], tt;
int f[120][6020];
int v[6020];
int g[6020];
int q[6020], qq;
char c[120];
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
	v[p] = 1;
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
	f[0][0] = 1;
	int z = 1;
	for (int i = 0; i < m; i++)
	{
		z = z * 26 % mod;
		for (int j = 0; j <= tt; j++)
		{
			for (int k = 0; k < 26; k++)
			{
				if (!v[t[j][k]])
				{
					f[i + 1][t[j][k]] = (f[i + 1][t[j][k]] + f[i][j]) % mod;
				}
			}
		}
	}
	for (int j = 0; j <= tt; j++)
	{
		z = (z + mod - f[m][j]) % mod;
	}
	printf("%d\n", z);
	return 0;
}