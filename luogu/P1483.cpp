#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000020];
int b[1000020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int o, x, y, z = 0;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d", &x, &y);
			b[x] += y;
		}
		else
		{
			scanf("%d", &x);
			for (int j = 1; j * j <= x; j++)
			{
				if (x % j == 0)
				{
					z += b[j];
					if (j * j < x)
					{
						z += b[x / j];
					}
				}
			}
			printf("%d\n", a[x] + z);
		}
	}
	return 0;
}