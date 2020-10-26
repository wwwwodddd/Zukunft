#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int x[10020];
int y[10020];
int l[10020];
int h[10020];
int e[10020];
int f[10020][1020];
int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		l[i] = 0;
		h[i] = m + 1;
	}
	for (int i = 0; i < p; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[x] = 1;
		l[x] = y;
		h[x] = z;
	}
	memset(f, 0x3f, sizeof f);
	memset(f[0], 0, sizeof f[0]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][min(j + x[i], m)] = min(f[i][min(j + x[i], m)], min(f[i - 1][j], f[i][j]) + 1);
		}
		for (int j = y[i] + 1; j <= m; j++)
		{
			f[i][j - y[i]] = min(f[i - 1][j], f[i][j - y[i]]);
		}
		for (int j = 1; j <= l[i]; j++)
		{
			f[i][j] = 0x3f3f3f3f;
		}
		for (int j = h[i]; j <= m; j++)
		{
			f[i][j] = 0x3f3f3f3f;
		}
	}
	int ans = *min_element(f[n] + 1, f[n] + m + 1);
	if (ans < 0x3f3f3f3f)
	{
		printf("1\n%d\n", ans);
	}
	else
	{
		for (int i = n; i > 0; i--)
		{
			int ans = *min_element(f[i] + 1, f[i] + m + 1);
			if (ans < 0x3f3f3f3f)
			{
				int cnt = 0;
				for (int j = 1; j <= i; j++)
				{
					cnt += e[j];
				}
				printf("0\n%d\n", cnt);
				break;
			}
		}
	}
	return 0;
}