#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
int a[120];
int f[120][120][5020];
void inc(int &x, long long y)
{
	x = (x + y) % p;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	f[0][0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; k + (a[i + 1] - a[i]) * j <= m; k++)
			{
				inc(f[i + 1][j + 1][k + (a[i + 1] - a[i]) * j], f[i][j][k]);
				inc(f[i + 1][j][k + (a[i + 1] - a[i]) * j], (long long)f[i][j][k] * (j + 1));
				inc(f[i + 1][j - 1][k + (a[i + 1] - a[i]) * j], (long long)f[i][j][k] * j);
			}
		}
	}
	int z = 0;
	for (int i = 0; i <= m; i++)
	{
		inc(z, f[n][0][i]);
	}
	printf("%d\n", z);
	return 0;
}