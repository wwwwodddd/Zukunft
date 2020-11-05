#include <bits/stdc++.h>
using namespace std;
int m, n, x, y, z;
map<int, vector<pair<int, int> > > a;
int f[1020];
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[z].push_back(make_pair(x, y));
	}
	for (auto i: a)
	{
		for (int j = m; j >= 0; j--)
		{
			for (pair<int, int> k: i.second)
			{
				if (j >= k.first)
				{
					f[j] = max(f[j], f[j - k.first] + k.second);
				}
			}
		}
	}
	printf("%d\n", f[m]);
	return 0;
}