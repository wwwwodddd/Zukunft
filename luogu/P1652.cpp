#include <bits/stdc++.h>
using namespace std;
int n, xa, ya, xb, yb, z;
int x[60], y[60], r[60];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &y[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &r[i]);
	}
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	for (int i = 0; i < n; i++)
	{
		if (((xa - x[i]) * (xa - x[i]) + (ya - y[i]) * (ya - y[i]) < r[i] * r[i]) ^ ((xb - x[i]) * (xb - x[i]) + (yb - y[i]) * (yb - y[i]) < r[i] * r[i]))
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}