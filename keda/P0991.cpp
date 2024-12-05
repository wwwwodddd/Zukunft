#include <bits/stdc++.h>
using namespace std;
int n, m, a[60];
int f[60][20];
int g[60][20];
int mn = 1e9;
int mx = 0;
void dp()
{
	f[0][0] = 1;
	g[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int s = 0;
			f[i][j] = 1e8;
			g[i][j] = 0;
			for (int k = i - 1; k >= 0; k--)
			{
				s = (s + a[k] % 10 + 10) % 10;
				if ((j > 1 || k == 0) && k >= j - 1)
				{
					f[i][j] = std::min(f[i][j], f[k][j - 1] * s);
					g[i][j] = std::max(g[i][j], g[k][j - 1] * s);
				}
			}
		}
	}
	mn = min(mn, f[n][m]);
	mx = max(mx, g[n][m]);
	return;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		dp();
		rotate(a, a + 1, a + n);
	}
	printf("%d\n%d\n", mn, mx);
	return 0;
}