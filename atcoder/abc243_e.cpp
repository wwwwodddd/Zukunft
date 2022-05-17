#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[320][320];
int x[100020];
int y[100020];
int z[100020];
int main()
{
	cin >> n >> m;
	memset(d, 0x3f, sizeof d);
	for (int i = 0; i < m; i++)
	{
		cin >> x[i] >> y[i] >> z[i];
		d[x[i]][y[i]] = z[i];
		d[y[i]][x[i]] = z[i];
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int f = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[x[i]][j] + d[j][y[i]] <= z[i])
			{
				f++;
				break;
			}
		}
	}
	cout << f << endl;
	return 0;
}
