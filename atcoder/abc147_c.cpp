#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<pair<int, int> > a[20];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x >> y;
			a[i].push_back(make_pair(x - 1, y));
		}
	}
	for (int i = 0; i < 1 << n; i++)
	{
		int f = 1;
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				for (pair<int, int> k: a[j])
				{
					if ((i >> k.first & 1) != k.second)
					{
						f = 0;
					}
				}
			}
		}
		if (f)
		{
			z = max(z, __builtin_popcount(i));
		}
	}
	cout << z << endl;
	return 0;
}
