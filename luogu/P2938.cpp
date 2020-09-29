#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[60][60];
int f[500020];
int main() {
	scanf("%d%d%d", &n, &t, &m);
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < t; i++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i < t; i++)
	{
		for (int k = 0; k <= m; k++)
		{
			f[k] = k;
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = a[i-1][j]; k <= m; k++)
			{
				f[k] = max(f[k], f[k - a[i-1][j]] + a[i][j]);
			}
		}
		m = f[m];
	}
	printf("%d\n", m);
	return 0;
}
