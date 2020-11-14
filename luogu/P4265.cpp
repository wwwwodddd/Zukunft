#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[252];
int f[252];
int s[252];
int d[252];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = m;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s[i] >> d[i];
	}
	f[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = f[i]; j < m; j++)
		{
			if (s[j] >= a[i])
			{
				for (int k = i + 1; k <= i + d[j]; k++)
				{
					if (s[j] >= a[k])
					{
						f[k] = min(f[k], j);
					}
				}
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}