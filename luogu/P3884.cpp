#include <bits/stdc++.h>
using namespace std;
int c[120];
int d[120];
int f[120];
int n, x, y, z, md;
int main()
{
	scanf("%d", &n);
	c[d[1]]++;
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		f[y] = x;
		d[y] = d[x] + 1;
		md = max(md, d[y]);
		c[d[y]]++;
	}
	scanf("%d%d", &x, &y);
	while (x != y)
	{
		if (d[x] < d[y])
		{
			y = f[y];
			z++;
		}
		else
		{
			x = f[x];
			z += 2;
		}
	}
	printf("%d\n", md + 1);
	printf("%d\n", *max_element(c, c + n));
	printf("%d\n", z);
	return 0;
}