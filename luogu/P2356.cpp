#include <bits/stdc++.h>
using namespace std;
int n, z = -1;
int a[1020][1020];
int r[1020];
int c[1020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!a[i][j])
			{
				z = max(z, r[i] + c[j]);
			}
		}
	}
	if (z < 0)
	{
		puts("Bad Game!");
	}
	else
	{
		printf("%d\n", z);
	}
	return 0;
}