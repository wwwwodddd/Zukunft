#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[52];
int f[52][52][52][52];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int r = 1; r <= n; r++)
	{
		for (int l = r; l > 0; l--)
		{
			for (int u = 1; u <= 50; u++)
			{
				for (int d = u; d > 0; d--)
				{
					int &g = f[l][r][d][u];
					g = max(g, f[l][r][d][u - 1]);
					g = max(g, f[l][r][d + 1][u]);
					g = max(g, f[l + 1][r][d][u] + (d == a[l]));
					g = max(g, f[l][r - 1][d][u] + (u == a[r]));
					if (l < r)
					{
						g = max(g, f[l + 1][r - 1][d][u] + (d == a[r]) + (u == a[l]));
					}
					z = max(z, g);
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}