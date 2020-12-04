#include <bits/stdc++.h>
using namespace std;
int n, z;
int v[1000020];
int l[1000020];
int r[1000020];
bool ok(int x, int y)
{
	if (x == -1 && y == -1)
	{
		return true;
	}
	if (x > 0 && y > 0 && v[x] == v[y] && ok(l[x], r[y]) && ok(r[x], l[y]))
	{
		return true;
	}
	return false;
}
int dfs(int x)
{
	if (x == -1)
	{
		return 0;
	}
	int s = dfs(l[x]) + 1 + dfs(r[x]);
	if (ok(l[x], r[x]))
	{
		z = max(z, s);
	}
	return s;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
	}
	dfs(1);
	printf("%d\n", z);
	return 0;
}