#include <bits/stdc++.h>
using namespace std;
int s, n, m;
int f[20020];
int a[120][120];
int main()
{
	cin >> s >> n >> m;
	for (int i = 0; i < s; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j][i];
			a[j][i] = a[j][i] * 2 + 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sort(a[i], a[i] + s);
		for (int j = m; j > 0; j--)
		{
			for (int k = 1; k <= s; k++)
			{
				if (j >= a[i][k - 1])
				{
					f[j] = max(f[j], f[j - a[i][k - 1]] + i * k);
				}
			}
		}
	}
	cout << f[m] << endl;
	return 0;
}