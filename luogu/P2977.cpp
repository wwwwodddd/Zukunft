#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<int> a[100020];
int dfs(int x, int y)
{
	int s = a[x].size() == 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			s += dfs(i, x);
		}
	}
	z += min(s / 2, m);
	if (s / 2 >= m)
	{
		return 0;
	}
	else
	{
		return s & 1;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", z);
	return 0;
}