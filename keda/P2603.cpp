#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
int d[100020];
int main()
{
	scanf("%d", &n);
	d[1]++;
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		d[x]++;
		d[y]++;
	}
	z = n - 1;
	for (int i = 1; i <= n; i++)
	{
		while (d[i] > 1)
		{
			d[i] = (d[i] + 1) / 2;
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}