#include <bits/stdc++.h>
using namespace std;
int n, t, x, y;
vector<int> a[10020];
int v[1000020], l[1000020];
bool dfs(int x)
{
	for (int i : a[x])
	{
		if (v[i] != t)
		{
			v[i] = t;
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
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(i);
		a[y].push_back(i);
	}
	for (t = 1; t <= n + 1; t++)
	{
		if (!dfs(t))
		{
			printf("%d\n", t - 1);
			break;
		}
	}
	return 0;
}
