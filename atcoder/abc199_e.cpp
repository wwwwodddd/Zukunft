#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<pair<int, int> > a[20];
long long f[262145];
bool ok(int i)
{
	for (pair<int, int> k : a[__builtin_popcount(i)])
	{
		int c = 0;
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				if (j < k.first)
				{
					c++;
				}
			}
		}
		if (c > k.second)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
	}
	f[0] = 1;
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (~i >> j & 1)
			{
				if (ok(i | 1 << j))
				{
					f[i | 1 << j] += f[i];
				}
			}
		}
	}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}
