#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[220];
int v[220], l[220];
bool dfs(int x)
{
	for (int i: a[x])
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
	for (int i = 1; i <= n; i++)
	{
		int l;
		scanf("%d", &l);
		a[i].resize(l);
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int z = 0;
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