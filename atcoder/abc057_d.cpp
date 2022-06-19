#include <bits/stdc++.h>
using namespace std;
int n, a, b;
long long x;
long long f[60][60];
long long g[60][60];
int main()
{
	cin >> n >> a >> b;
	g[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		for (int j = 0; j <= i; j++)
		{
			if (f[i + 1][j + 1] < f[i][j] + x)
			{
				f[i + 1][j + 1] = f[i][j] + x;
				g[i + 1][j + 1] = g[i][j];
			}
			else if (f[i + 1][j + 1] == f[i][j] + x)
			{
				g[i + 1][j + 1] += f[i][j];
			}
			if (f[i + 1][j] < f[i][j])
			{
				f[i + 1][j] = f[i][j];
				g[i + 1][j] = g[i][j];
			}
			else if (f[i + 1][j] == f[i][j])
			{
				g[i + 1][j] += g[i][j];
			}
		}
	}
	long long x = 0, y = 1;
	long long z = 0;
	for (int i = a; i <= b; i++)
	{
		if (x * i < f[n][i] * y)
		{
			x = f[n][i];
			y = i;
			z = g[n][i];
		}
		else if (x * i == f[n][i] * y)
		{
			z += g[n][i];
		}
	}
	cout << fixed << setprecision(9) << double(x) / y << endl << z << endl;
	return 0;
}