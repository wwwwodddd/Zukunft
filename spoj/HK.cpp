#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n, m;
int f[501][1001];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		double z = 0;
		f[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				f[i + 1][j] = f[i][j] * 32LL % p;
			}
			long long x;
			scanf("%lld", &x);
			for (int j = 0; j < 32; j++)
			{
				if (x >> j & 1)
				{
					z += pow(2, j) * 31;
				}
				else
				{
					z += pow(2, j);
				}
			}
			for (int j = 0; j < 32; j++)
			{
				for (long long k = 0; k <= m - (x ^ (1LL << j)); k++)
				{
					long long nk = k + (x ^ (1LL << j));
					f[i + 1][nk] = (f[i + 1][nk] + f[i][k]) % p;
				}
			}
		}
		printf("%d %.6f\n", f[n][m], z / 64);
	}
	return 0;
}