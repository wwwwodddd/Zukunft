#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[120];
long long f[120][120], z = 1e18;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		memset(f, 0x3f, sizeof f);
		f[0][n] = 0;
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				long long s = 0;
				for (int l = k; l <= n; l++)
				{
					f[j][k] = min(f[j][k], s + f[j - 1][l]);
					s += a[l] * (l - k);
				}
			}
		}
		z = min(z, f[m][0]);
		rotate(a, a + 1, a + n);
	}
	printf("%lld\n", z);
	return 0;
}