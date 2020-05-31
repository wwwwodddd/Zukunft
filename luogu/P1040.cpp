#include <bits/stdc++.h>
using namespace std;
int n;
long long f[50][50];
int p[50][50];
void dfs(int x, int y)
{
	if (x <= y)
	{
		printf("%d ", p[x][y]);
		dfs(x, p[x][y]-1);
		dfs(p[x][y]+1, y);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i][i];
		f[i][i-1] = 1;
		f[i+1][i] = 1;
		p[i][i] = i;
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				if (f[i][j] < f[i][k-1] * f[k+1][j] + f[k][k])
				{
					f[i][j] = f[i][k-1] * f[k+1][j] + f[k][k];
					p[i][j] = k;
				}
			}
		}
	}
	cout << f[1][n] << endl;
	dfs(1, n);
	return 0;
}