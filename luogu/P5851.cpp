#include <bits/stdc++.h>
using namespace std;
int n, m, f[302][302];
int a[302][302][302];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int w, l, r;
		cin >> w >> l >> r; 
		for (int j = l; j <= r; j++)
		{
			a[j][l][r] = max(a[j][l][r], w);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			for (int k = i; k <= n; k++)
			{
				a[i][j][k] = max(a[i][j][k], max(a[i][j+1][k], a[i][j][k-1]));
			}
		}
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i; j <= n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				f[i][j] = max(f[i][j], f[i][k-1] + f[k+1][j] + a[k][i][j]);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}