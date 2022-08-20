#include <bits/stdc++.h>
using namespace std;
int t, n, x;
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
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &x);
				if (x)
				{
					a[i].push_back(j);
				}
			}
		}
		memset(l, 0, sizeof l);
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			memset(v, 0, sizeof v);
			if (dfs(i))
			{
				z++;
			}
		}
		puts(z < n ? "No" : "Yes");
	}
	return 0;
}
