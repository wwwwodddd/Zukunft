#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int inv2 = (p + 1) / 2;
int n;
int t[500020][26], tt;
int sz[500020];
int v[500020];
long long z[500020];
char c[500020];
void ins(char *s, int i)
{
	int p = 0;
	sz[p]++;
	for (; *s; s++)
	{
		if (t[p][*s - 'a'] == 0)
		{
			t[p][*s - 'a'] = ++tt;
		}
		p = t[p][*s - 'a'];
		sz[p]++;
	}
	v[p] = i;
}
void dfs(int x, long long w)
{
	long long u = sz[x];
	if (v[x] > 0)
	{
		z[v[x]] = w;
		w++;
		u--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (t[x][i])
		{
			dfs(t[x][i], (w + (u - sz[t[x][i]]) * inv2) % p);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", c);
		ins(c, i);
	}
	dfs(0, 1);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}