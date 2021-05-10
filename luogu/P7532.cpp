#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, z;
long long f[4][155][155];
long long g[4][155][155];
char s[155];
long long S(long long f[155][155], int x1, int x2, int y1, int y2)
{
	return (f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1] + 2 * mod) % mod;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s + 1);
		swap(f, g);
		memset(f, 0, sizeof f);
		for (int l = 1; l <= n; l++)
		{
			for (int r = l; r <= n && s[r] != '.'; r++)
			{
				f[0][l][r] = 1 + S(g[0], l, r, l, r);
				f[2][l][r] = (S(g[2], 1, l, l, r) + S(g[0], 1, l - 1, l, r)) % mod;
				f[1][l][r] = (S(g[1], l, r, r, n) + S(g[0], l, r, r + 1, n)) % mod;
				f[3][l][r] = (S(g[3], 1, l, r, n) + S(g[0], 1, l - 1, r + 1, n) + S(g[1], 1, l - 1, r, n) + S(g[2], 1, l, r + 1, n)) % mod;
				z = (z + f[0][l][r] + f[1][l][r] + f[2][l][r] + f[3][l][r]) % mod;
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int l = 1; l <= n; l++)
				for (int r = 1; r <= n; r++)
					f[j][l][r] = (f[j][l][r] + f[j][l][r - 1]) % mod;
			for (int l = 1; l <= n; l++)
				for (int r = 1; r <= n; r++)
					f[j][l][r] = (f[j][l][r] + f[j][l - 1][r]) % mod;
		}
	}
	printf("%d\n", z);
	return 0;
}