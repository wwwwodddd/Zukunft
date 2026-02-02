#include <bits/stdc++.h>
using namespace std;
int t, n, m, c;
vector<vector<int> > a;
int dfs(int x, int y)
{
	int s = 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			s += dfs(i, x);
		}
	}
	if (s % m == 0)
	{
		c++;
	}
	return s;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		a.clear();
		a.resize(n + 1);
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		c = 0;
		dfs(1, 0);
		if (c * m == n)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}