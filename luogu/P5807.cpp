#include <bits/stdc++.h>
using namespace std;
const int mod = 1000003;
typedef long long ll;
int t, n;
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
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		ll z = 1;
		for (int i = 0, s, x; i < n; i++)
		{
			scanf("%d", &s);
			z = z * f[s - !!i] % mod;
			for (int j = 0; j < s; j++)
			{
				scanf("%d", &x);
				x--;
				a[i][x]--;
				a[x][x]++;
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				while (a[j][i])
				{
					ll t = a[i][i] / a[j][i];
					for (int k = 0; k < n; k++)
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