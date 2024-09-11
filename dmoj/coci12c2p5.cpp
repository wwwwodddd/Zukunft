#include <bits/stdc++.h>
using namespace std;
int mn[220];
int mx[220];
int L[220];
int R[220];
int v[220];
int l[220];
int z[220];
int n, m;
bool dfs(int x)
{
	for (int i = mn[x]; i <= mx[x]; i++)
	{
		if (L[i] <= x && x<= R[i] && !v[i])
		{
			v[i] = 1;
			if (!l[i] || dfs(l[i]))
			{
				l[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		L[i] = mn[i] = 1;
		R[i] = mx[i] = n;
	}
	for (int i = 0; i < m; i++)
	{
		int o, x, y, v;
		scanf("%d%d%d%d", &o, &x, &y, &v);
		L[v] = max(L[v], x);
		R[v] = min(R[v], y);
		for(int j = x; j <= y; j++)
		{
			if (o == 1)
			{
				mx[j] = min(mx[j], v);
			}
			else
			{
				mn[j] = max(mn[j], v);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		memset(v, 0, sizeof v);
		if (!dfs(i))
		{
			puts("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		z[l[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", z[i]);
	}
	return 0;
}
