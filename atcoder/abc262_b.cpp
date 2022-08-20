#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int a[120][120];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				if (a[i][j] && a[j][k] && a[i][k])
				{
					z++;
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}
