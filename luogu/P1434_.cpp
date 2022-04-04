#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[120][120];
int f[120][120];
int F(int x, int y)
{
	if (f[x][y] > 0)
	{
		return f[x][y];
	}
	int re = 0;
	if (x > 0 && a[x][y] > a[x - 1][y])
	{
		re = max(re, F(x - 1, y));
	}
	if (x + 1 < n && a[x][y] > a[x + 1][y])
	{
		re = max(re, F(x + 1, y));
	}
	if (y > 0 && a[x][y] > a[x][y - 1])
	{
		re = max(re, F(x, y - 1));
	}
	if (y + 1 < m && a[x][y] > a[x][y + 1])
	{
		re = max(re, F(x, y + 1));
	}
	return f[x][y] = re + 1;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			z = max(z, F(i, j));
		}
	}
	cout << z << endl;
	return 0;	
}

