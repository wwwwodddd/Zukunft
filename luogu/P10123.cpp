#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[120];
int c[120];
int p[120];
bool ok()
{
	int c2p[120] = {};
	int p2c[120] = {};
	for (int i = 0; i <= k; i++)
	{
		if (c2p[c[i]] > 0 && c2p[c[i]] != p[i])
		{
			return false;
		}
		if (p2c[p[i]] > 0 && p2c[p[i]] != c[i])
		{
			return false;
		}
		c2p[c[i]] = p[i];
		p2c[p[i]] = c[i];
	}
	int j = 1;
	for (int i = 0; i < m; i++)
	{
		if (c2p[a[i]] > 0)
		{
			if (j > c2p[a[i]])
			{
				return false;
			}
			j = c2p[a[i]];
		}
		else
		{
			while (j <= n && p2c[j] > 0)
			{
				j++;
			}
			if (j > n)
			{
				return false;
			}
			p2c[j] = a[i];
			c2p[a[i]] = j;
			j++;
		}
	}
	return true;
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> c[i] >> p[i];
	}
	for (int i = 1; i <= n; i++)
	{
		c[k] = 1;
		p[k] = i;
		if (ok())
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}