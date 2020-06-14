#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
int z[100020];
int n, m;
void dfs(int x, int y)
{
	if (z[x])
	{
		return;
	}
	z[x] = y;
	for (int i: a[x])
	{
		dfs(i, y);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[y].push_back(x);
	}
	for (int i = n; i > 0; i--)
	{
		dfs(i, i);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", z[i], i == n ? '\n' : ' ');
	}
	return 0;
}