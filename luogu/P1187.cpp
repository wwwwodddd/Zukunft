#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int a[1020][1020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &a[i][j]);
			s += !!a[i][j] + max(a[i][j] - a[i][j - 1], 0) + max(a[i][j] - a[i - 1][j], 0);
		}
	}
	printf("%d\n", 2 * s);
	return 0;
}