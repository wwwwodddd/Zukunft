#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<int> a[520];
int v[520], l[520];
bool dfs(int x)
{
	for (int i : a[x])
	{
		if (!v[i])
		{
			v[i] = true;
			if (l[i] == 0 || dfs(l[i]))
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
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(v, 0, sizeof v);
		if (dfs(i))
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}