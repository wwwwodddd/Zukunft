#include <bits/stdc++.h>
using namespace std;
char s[1020];
int x[1020];
int y[1020];
pair<int, int> z[1020];
pair<pair<int, int>, pair<int, int> > a[10000020];
// pair<pair<ta, tb>, pair<A, B> >
// at time ta, A arrived at intersection.
// at time tb, B arrived and was blocked.
int n, ac;
int c[1020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> x[i] >> y[i];
		z[i] = make_pair(2000000000, -1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i] == 'E' && s[j] == 'N')
			{
				if (x[i] + y[i] > x[j] + y[j] && x[i] <= x[j])
				{
					a[ac++] = make_pair(make_pair(x[j] - x[i], y[i] - y[j]), make_pair(i, j));
				}
				if (x[i] + y[i] < x[j] + y[j] && y[i] >= y[j])
				{
					a[ac++] = make_pair(make_pair(y[i] - y[j], x[j] - x[i]), make_pair(j, i));
				}
			}
		}
	}
	sort(a, a + ac);
	for (int i = 0; i < ac; i++)
	{
		if (a[i].first.first <= z[a[i].second.first].first)
		{
			z[a[i].second.second] = min(z[a[i].second.second], make_pair(a[i].first.second, a[i].second.first));
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = z[i].second; j != -1; j = z[j].second)
		{
			c[j]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", c[i]);
	}
	return 0;
}