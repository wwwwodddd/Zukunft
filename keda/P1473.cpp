#include <bits/stdc++.h>
using namespace std;
int l, n, m, x, y, z;
vector<int> a[1020];
int c[1020];
int v[1020];
int s[1020];
void dfs(int x)
{
	v[x] = 1;
	c[x]++;
	for (int i : a[x])
	{
		if (!v[i])
		{
			dfs(i);
		}
	}
}
int main()
{
	scanf("%d%d%d", &l, &n, &m);
	for (int i = 0; i < l; i++)
	{
		scanf("%d", &s[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 0; i < l; i++)
	{
		memset(v, 0, sizeof v);
		dfs(s[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == l)
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}