#include <bits/stdc++.h>
using namespace std;
int n;
int a[2][100020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int u = 0, d = 0;
	long long z = 0;
	for (int i = 0; i < n; i++)
	{
		u += a[0][i] - 1;
		d += a[1][i] - 1;
		z += abs(u + d);
		while (u < 0 && d > 0)
		{
			u++;
			d--;
			z++;
		}
		while (u > 0 && d < 0)
		{
			u--;
			d++;
			z++;
		}
	}
	printf("%lld\n", z);
	return 0;
}