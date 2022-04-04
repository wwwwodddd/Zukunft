#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
int p[200020];
int l[200020];
int r[200020];
set<int> s;
void dfs(int x, int d)
{
	if (x == 0)
	{
		printf("%d\n", d / 2);
		return;
	}
	dfs(l[x], d % 2 == 0 ? d + 1 : d);
	dfs(r[x], d % 2 == 1 ? d + 1 : d);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	s.insert(a[1]);
	for (int i = 2; i <= n; i++)
	{
		set<int>::iterator it = s.lower_bound(a[i]);
		int u = -1;
		if (it != s.end())
		{
			u = *it;
		}
		if (it != s.begin())
		{
			*it--;
			if (u == -1 || p[u] < p[*it])
			{
				u = *it;
			}
		}
		if (a[i] > u)
		{
			r[u] = a[i];
		}
		else
		{
			l[u] = a[i];
		}
		s.insert(a[i]);
	}
	dfs(a[1], 0);
	return 0;
}