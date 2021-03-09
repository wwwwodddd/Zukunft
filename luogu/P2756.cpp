#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<int> a[120];
int v[120], l[120];
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
	while (true)
	{
		scanf("%d%d", &x, &y);
		if (x == -1 && y == -1)
		{
			break;
		}
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
	for (int i = n + 1; i <= m; i++)
	{
		if (l[i])
		{
			printf("%d %d\n", l[i], i);
		}
	}
	return 0;
}