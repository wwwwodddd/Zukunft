#include <bits/stdc++.h>
int n, x, l, v, z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x < l)
		{
			v = 1;
		}
		else if (x > l && v)
		{
			z++;
			v = 0;
		}
		l = x;
	}
	printf("%d\n", z);
	return 0;
}