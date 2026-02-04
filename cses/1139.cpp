#include <bits/stdc++.h>
using namespace std;
int n, x, y;
set<int> s[200020];
vector<int> a[200020];
int z[200020];
void dfs(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			if (s[i].size() > s[x].size())
			{
				s[x].swap(s[i]);
			}
			for (int i : s[i])
			{
				s[x].insert(i);
			}
			s[i].clear();
		}
	}
	z[x] = s[x].size();
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s[i].insert(x);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", z[i]);
	}
	return 0;
}