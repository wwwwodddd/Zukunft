#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int t, n, m;
int s[320][320];
long long f[320][320];
int S(int xa, int xb, int ya, int yb)
{
	xa--;
	ya--;
	return s[xb][yb] - s[xb][ya] - s[xa][yb] + s[xa][ya];
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		memset(s, 0, sizeof s);
		memset(f, 0, sizeof f);
		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			s[x][y] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			f[i][i] = 1 - s[i][i];
			f[i + 1][i] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
			}
		}
		for (int l = 1; l < n; l++)
		{
			for (int i = 1; i + l <= n; i++)
			{
				int j = i + l;
				for (int k = i; k <= j; k++)
				{
					if (S(i, i, i, k) == 0 && S(k + 1, j, i, k) == 0)
					{
						f[i][j] = (f[i][j] + f[i + 1][k] * f[k + 1][j]) % p;
					}
				}
			}
		}
		cout << f[1][n] << endl;
	}
	return 0;
}