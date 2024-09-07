#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[500020];
int y[500020];
char o[500020];
int p[500020];
int q[500020];
long long kx, bx, ky, by;
// x -> kx * x + bx
// y -> ky * y + by
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf(" %c", &o[i]);
		if (o[i] == 'm')
		{
			scanf("%d%d", &p[i], &q[i]);
		}
	}
	kx = ky = 1;
	for (int i = m - 1; i >= 0; i--)
	{
		if (o[i] == 'm')
		{
			bx += p[i];
			by += q[i];
		}
		else if (o[i] == 'x')
		{
			kx *= -1;
			bx *= -1;
		}
		else if (o[i] == 'y')
		{
			ky *= -1;
			by *= -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%lld %lld\n", kx * x[i] + bx, ky * y[i] + by);
	}
	return 0;
}
