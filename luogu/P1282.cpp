#include <bits/stdc++.h>
using namespace std;
const int m = 5010;
int n, x, y;
int f[2 * m];
int g[2 * m];
int main()
{
	scanf("%d", &n);
	memset(f, 0x3f, sizeof f);
	f[m] = 0;
	for (int i = 0; i < n; i++)
	{
		memcpy(g, f, sizeof g);
		memset(f, 0x3f, sizeof f);
		scanf("%d%d", &x, &y);
		for (int j = m - 5 * n; j <= m + 5 * n; j++)
		{
			f[j] = min(g[j + x - y], g[j - x + y] + 1);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (min(f[m - i], f[m + i]) < n)
		{
			printf("%d\n", min(f[m - i], f[m + i]));
			break;
		}
	}
	return 0;
}