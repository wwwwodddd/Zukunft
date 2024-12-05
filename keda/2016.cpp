#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[18];
pair<int, int> f[262144];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	memset(f, 0x3f, sizeof f);
	f[0] = make_pair(0, m);
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (~i >> j & 1)
			{
				if (f[i].second + a[j] > m)
				{
					f[i | 1 << j] = min(f[i | 1 << j], make_pair(f[i].first + 1, a[j]));
				}
				else
				{
					f[i | 1 << j] = min(f[i | 1 << j], make_pair(f[i].first, f[i].second + a[j]));
				}
			}
		}
	}
	cout << f[(1 << n) - 1].first << endl;
	return 0;
}