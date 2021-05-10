#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
int t, n;
char s[120];
int a[120][120];
int f[200020];
int main()
{
	for (int i = f[0] = 1; i < 200010; i++)
	{
		f[i] = (ll)f[i - 1] * i % mod;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%*d%s", &n, s + 1);
		memset(a, 0, sizeof a);
		ll z = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%1d", &a[i][j]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == 'S')
			{
				a[0][i] = 1;
			}
			else if(s[i] == 'R')
			{
				a[i][0] = 1;
			}
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i != j)
				{
					a[j][j] += a[i][j];
					a[i][j] = -a[i][j];
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i][i] == 0)
			{
				a[i][i] = 1;
			}
			z = z * f[a[i][i] - 1] % mod;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				while (a[j][i])
				{
					ll t = a[i][i] / a[j][i];
					for (int k = 1; k <= n; k++)
					{
						a[i][k] = (a[i][k] - a[j][k] * t) % mod;
					}
					swap(a[i], a[j]);
					z = -z;
				}
			}
			z = z * a[i][i] % mod;
		}
		printf("%lld\n", (z + mod) % mod);
	}
	return 0;
}