#include <bits/stdc++.h>
using namespace std;
pair<int, pair<int, int> > a[420];
int n, z;
int f[40020];
int g[40020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second.first >> a[i].first >> a[i].second.second;
	}
	f[0] = 1;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i].second.first; j <= a[i].first; j++)
		{
			if (f[j])
			{
				g[j] = 0;
			}
			else if (f[j - a[i].second.first] && g[j - a[i].second.first] < a[i].second.second)
			{
				z = max(z, j);
				f[j] = 1;
				g[j] = g[j - a[i].second.first] + 1;
			}
		}
	}
	cout << z << endl;
	return 0;
}