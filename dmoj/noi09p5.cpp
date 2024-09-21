#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[505], t[505];
int f[2][505][505];
inline void inc(int &f, int &c)
{
	f = (f + c) % 1024523;
}
int main()
{
	scanf("%d%d%s%s", &n, &m, s, t);
	f[0][0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		memset(f[i + 1 & 1], 0, sizeof f[0]);
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				int l = i + j - k;
				if (s[i] == s[k])
				{
					inc(f[i + 1 & 1][j][k + 1], f[i & 1][j][k]);
				}
				if (s[i] == t[l])
				{
					inc(f[i + 1 & 1][j][k], f[i & 1][j][k]);
				}
				if (t[j] == s[k])
				{
					inc(f[i & 1][j + 1][k + 1], f[i & 1][j][k]);
				}
				if (t[j] == t[l])
				{
					inc(f[i & 1][j + 1][k], f[i & 1][j][k]);
				}
			}
		}
	}
	printf("%d\n", f[n & 1][m][n]);
	return 0;
}