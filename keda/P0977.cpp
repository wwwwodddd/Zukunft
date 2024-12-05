#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[1020][1020];
long long f[1020][1020];
int main()
{
	scanf("%d%d", &n, &m);
	memset(f, 0xc0, sizeof f);
	f[1][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	for (int j = 1; j <= m; j++)
	{
		long long s = -1e18;
		for (int i = 1; i <= n; i++)
		{
			s = max(s, f[i][j - 1]) + a[i][j];
			f[i][j] = max(f[i][j], s);
		}
		s = -1e18;
		for (int i = n; i > 0; i--)
		{
			s = max(s, f[i][j - 1]) + a[i][j];
			f[i][j] = max(f[i][j], s);
		}
	}
	printf("%lld\n", f[n][m]);
	return 0;
}