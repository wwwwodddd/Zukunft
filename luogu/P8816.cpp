#include <bits/stdc++.h>
using namespace std;
int n, m, z;
pair<int, int> a[501];
int f[501][101];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = i + 1; k < n; k++)
			{
				if (a[i].second <= a[k].second)
				{
					int d = abs(a[i].first - a[k].first) + abs(a[i].second - a[k].second) - 1;
					if (j + d <= m)
					{
						f[k][j + d] = max(f[k][j + d], f[i][j] + 1);
						z = max(z, f[k][j + d]);
					}
				}
			}
		}
	}
	cout << z + m + 1 << endl;
	return 0;
}