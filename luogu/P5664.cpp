#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
int n, m, a[120][2020];
ll z = 1, s[120], f[120][220];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			s[i] = (s[i] + a[i][j]) % mod;
		}
		z = z * (s[i] + 1) % mod;
	}
	z--;
	for (int k = 0; k < m; k++)
	{
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = -i; j <= i; j++)
			{
				f[i+1][j] = (f[i+1][j] + f[i][j]) % mod;
				f[i+1][j+1] = (f[i+1][j+1] + f[i][j] * a[i][k]) % mod;
				f[i+1][j-1] = (f[i+1][j-1] + f[i][j] * (s[i] - a[i][k])) % mod;
			}
		}
		for (int j = 1; j <= n; j++)
		{
			z = (z + mod - f[n][j]) % mod;
		}
	}
	printf("%lld\n", z);
	return 0;
}