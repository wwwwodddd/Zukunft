#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[120];
char c[120];
int d[120];
pair<int, pair<int, int>> a[260];
bool check(int root, int times)
{
	for (int i = 0; i < n; i++)
	{
		c[i] = '0';
		d[i] = times;
	}
	c[root] = '1';
	for (int i = 0; i < m; i++)
	{
		if (c[a[i].second.first] == '0' && c[a[i].second.second] == '0')
		{
		}
		else if (c[a[i].second.first] == '0' && c[a[i].second.second] == '1')
		{
			if (d[a[i].second.second] > 0)
			{
				d[a[i].second.second]--;
				c[a[i].second.first] = '1';
			}
		}
		else if (c[a[i].second.first] == '1' && c[a[i].second.second] == '0')
		{
			if (d[a[i].second.first] > 0)
			{
				d[a[i].second.first]--;
				c[a[i].second.second] = '1';
			}
		}
		else if (c[a[i].second.first] == '1' && c[a[i].second.second] == '1')
		{
			if (d[a[i].second.first] > 0)
			{
				d[a[i].second.first]--;
			}
			if (d[a[i].second.second] > 0)
			{
				d[a[i].second.second]--;
			}
		}
	}
	return strcmp(s, c) == 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a[i].first, &a[i].second.first, &a[i].second.second);
		a[i].second.first--;
		a[i].second.second--;
	}
	sort(a, a + m);
	int rootcnt = 0;
	int mink = m + 1;
	int maxk = 0;
	for (int i = 0; i < n; i++)
	{
		bool cani = false;
		for (int k = 0; k <= m + 1; k++)
		{
			if (check(i, k))
			{
				mink = min(mink, k);
				maxk = max(maxk, k);
				cani = true;
			}
		}
		if (cani)
		{
			rootcnt++;
		}
	}
	printf("%d %d ", rootcnt, mink);
	if (maxk != m + 1)
	{
		printf("%d\n", maxk);
	}
	else
	{
		printf("Infinity\n");
	}
	return 0;
}