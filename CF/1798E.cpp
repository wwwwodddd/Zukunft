#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[300020];
int f[300020];
int g[300020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int mf = 0;
		f[n + 1] = 0;
		g[n + 1] = 0;
		for (int i = n; i > 0; i--)
		{
			if (i + a[i] > n)
			{
				f[i] = -1;
				g[i] = -1;
			}
			else
			{
				if (f[i + a[i] + 1] != -1)
				{
					f[i] = f[i + a[i] + 1] + 1;
				}
				else
				{
					f[i] = -1;
				}
				g[i] = g[i + a[i] + 1] + 1;
			}
			g[i] = max(g[i], mf + 1);
			mf = max(mf, f[i]);
		}
		for (int i = 1; i < n; i++)
		{
			int z = 2;
			if (a[i] == f[i + 1])
			{
				z = 0;
			}
			else if (f[i + 1] != -1 || a[i] <= g[i + 1])
			{
				z = 1;
			}
			cout << z << " ";
		}
		cout << endl;
	}
	return 0;
}