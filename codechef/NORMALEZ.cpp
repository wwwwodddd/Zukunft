#include <bits/stdc++.h>
using namespace std;
int t, n, c, l, x;
long long z;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		z = c = l = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (l != x)
			{
				l = x;
				c = 0;
			}
			z += ++c;
		}
		printf("%lld\n", z);
	}
	return 0;
}