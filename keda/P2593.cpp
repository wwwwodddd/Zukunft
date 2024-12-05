#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int c[5020];
int d[5020];
long long f[10020];
long long g[10020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		c[x]++;
		d[y]++;
	}
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			f[i + j] += (long long)c[i] * c[j];
			g[i + j] += (long long)d[i] * d[j];
		}
	}
	long long s = 0;
	for (int i = 0; i <= 2 * m; i++)
	{
		s += f[i];
		printf("%lld\n", s);
		s -= g[i];
	}
	return 0;
}