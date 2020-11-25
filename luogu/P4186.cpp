#include <bits/stdc++.h>
using namespace std;
int n, s, x, y, z;
vector<int> a[100020];
int f[100020];
int d[100020];
void dfs1(int x, int y)
{
	d[x] = d[y] + 1;
	f[x] = a[x].size() > 1 ? n : 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs1(i, x);
			f[x] = min(f[x], f[i] + 1);
		}
	}
}
void dfs2(int x, int y)
{
	if (f[x] <= d[x])
	{
		z += 2 - a[x].size();
	}
	for (int i: a[x])
	{
		if (i != y)
		{
			f[i] = min(f[i], f[x] + 1);
			dfs2(i, x);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs1(s, 0);
	dfs2(s, 0);
	printf("%d\n", z);
	return 0;
}