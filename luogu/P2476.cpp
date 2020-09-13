#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, s, x, f[80], g[80];
long long c[80][80];
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 0; i < 80; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
		}
	}
	f[s - 1] = 1;
	for (int i = 1; i < n; i++)
	{
		memcpy(g, f, sizeof g);
		memset(f, 0, sizeof f);
		scanf("%d", &x);
		for (int j = 0; j < s; j++)
		{
			for (int a = 1; a <= x; a++)
			{
				int u = g[j] * c[x-1][a-1] % mod;
				for (int b = 0; b <= a; b++)
				{
					f[j+x-a-b] = (f[j+x-a-b] + u * c[j][b] % mod * c[s+1-j][a-b]) % mod;
				}
			}
		}
		s += x;
	}
	printf("%d\n", f[0]);
	return 0;
}