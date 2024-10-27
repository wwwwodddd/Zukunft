#include <bits/stdc++.h>
using namespace std;
int t, n, c, l, x;
long long z;
int a[300020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		map<int, int> g;
		z = c = l = 0;
		int s1 = 0, s2 = 0, j = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] == 2)
			{
				while (j <= i)
				{
					g[s1]++;
					s1 += a[j] - 2;
					j++;
				}
			}
			if (l != a[i])
			{
				l = a[i];
				c = 0;
			}
			if (l != 2)
			{
				z += ++c;
			}
			s2 += a[i] - 2;
			z += g[s2];
		}
		printf("%lld\n", z);
	}
	return 0;
}