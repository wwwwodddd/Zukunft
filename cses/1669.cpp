#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int v[100020];
int d[100020];
int f[100020];
vector<int> a[100020];
void dfs(int x, int y)
{
	f[x] = y;
	d[x] = d[y] + 1;
	v[x] = 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			if (v[i])
			{
				printf("%d\n", d[x] - d[i] + 2);
				printf("%d", i);
				for (int j = x; j != i; j = f[j])
				{
					printf(" %d", j);
				}
				printf(" %d\n", i);
				exit(0);
			}
			else
			{
				dfs(i, x);
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
		{
			dfs(i, 0);
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}