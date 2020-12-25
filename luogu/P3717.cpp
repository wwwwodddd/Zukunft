#include <bits/stdc++.h>
using namespace std;
int a[120][120];
int n, m, r, x, y, z;
int main()
{
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r)
				{
					if (!a[i][j])
					{
						a[i][j] = 1;
						z++;
					}
				}
			}
		}
	}
	printf("%d\n", z);
	return 0;
}