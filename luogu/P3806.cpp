#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > a[10020];
set<int> s[10020];
int l[120];
bool z[120];
void dfs(int x, int y, int d)
{
	s[x].insert(d);
	for (pair<int, int> i: a[x])
	{
		if (i.first != y)
		{
			dfs(i.first, x, d + i.second);
			if (s[x].size() < s[i.first].size())
			{
				s[x].swap(s[i.first]);
			}
			for (int j = 0; j < m; j++)
			{
				if (!z[j])
				{
					for (int k: s[i.first])
					{
						if (s[x].find(l[j] + 2 * d - k) != s[x].end())
						{
							z[j] = true;
						}
					}
				}
			}
			for (int j: s[i.first])
			{
				s[x].insert(j);
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &l[i]);
	}
	dfs(1, 0, 0);
	for (int i = 0; i < m; i++)
	{
		puts(z[i] ? "AYE" : "NAY");
	}
	return 0;
}