#include <bits/stdc++.h>
using namespace std;
int n, m, x, z;
int f[120][120];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &x);
			if (x)
			{
				f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
				z = max(z, f[i][j]);
			}
		}
	}
	printf("%d\n", z);
	return 0;
}