#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int h[520][520];
int f[250020];
int c[250020];
pair<int, pair<int, int> > a[500020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> h[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			a[m++] = make_pair(abs(h[i][j] - h[i][j - 1]), make_pair(i * n + j, i * n + j - 1));
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[m++] = make_pair(abs(h[i][j] - h[i - 1][j]), make_pair(i * n + j, i * n + j - n));
		}
	}
	for (int i = 0; i < n * n; i++)
	{
		f[i] = i;
		c[i] = 1;
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++)
	{
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y)
		{
			f[x] = y;
			c[y] += c[x];
			if (c[y] * 2 >= n * n)
			{
				cout << a[i].first << endl;
				break;
			}
		}
	}
	return 0;
}
