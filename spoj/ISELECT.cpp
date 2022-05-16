#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[10020];
int b[10020];
long long f[10020][2][2];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		long long z = 0;
		scanf("%d", &n);
		f[0][1][0] = -1e18;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			a[i] += b[i];
			z -= b[i];
			f[i][0][0] = max(f[i - 1][0][0], f[i - 1][0][1]);
			f[i][1][0] = max(f[i - 1][1][0], f[i - 1][1][1]);
			f[i][0][1] = f[i - 1][0][0] + a[i];
			f[i][1][1] = f[i - 1][1][0] + a[i];
		}
		printf("%lld\n", z + max(f[n][0][0], f[n][1][1]));
	}
	return 0;
}