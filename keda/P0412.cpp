#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[1020][1020];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	for (int i = 0; i < q; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		printf("%d\n", a[x2][y2] - a[x1][y2] - a[x2][y1] + a[x1][y1]);
	}
	return 0;
}