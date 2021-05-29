#include <bits/stdc++.h>
using namespace std;
int n, r, m, x, y;
int s[10020];
int z[10020];
vector<int> a[10020];
void dfs(int x, int y)
{
	s[x] = 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			s[x] += s[i];
			z[x] -= s[i] * s[i];
		}
	}
	z[x] += s[x] * s[x];
}
int main()
{
	scanf("%d%d%d", &n, &r, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(r, 0);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		printf("%d\n", z[x]);
	}
	return 0;
}