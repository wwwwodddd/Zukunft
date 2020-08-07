#include <bits/stdc++.h>
using namespace std;
int n;
int xa[252];
int ya[252];
int xb[252];
int yb[252];
int v[252];
int l[252];
bool dfs(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (ya[j] == yb[j] && ya[i] <= ya[j] && yb[j] <= yb[i] && xa[j] <= xa[i] && xb[i] <= xb[j] && !v[j])
		{
			v[j] = true;
			if (l[j] == 0 || dfs(l[j]))
			{
				l[j] = i;
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
		scanf("%d%d%d%d", &xa[i], &ya[i], &xb[i], &yb[i]);
		if (xa[i] > xb[i])
		{
			swap(xa[i], xb[i]);
		}
		if (ya[i] > yb[i])
		{
			swap(ya[i], yb[i]);
		}
	}
	int z = 0;
	for (int i = 1; i <= n; i++)
	{
		if (xa[i] == xb[i])
		{
			memset(v, 0, sizeof v);
			if (dfs(i))
			{
				z++;
			}
		}
	}
	printf("%d\n", n - z);
	return 0;
}