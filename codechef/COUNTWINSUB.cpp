#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		long long z = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			z += a[i];
		}
		int l = 1, c = 0;
		for (int r = 2; r <= n; r++)
		{
			if (a[r] && (a[r - 1] || a[r - 2]))
			{
				c++;
			}
			while (c > 0)
			{
				if (a[l] && (a[l + 1] || (l + 2 <= r && a[l + 2])))
				{
					c--;
				}
				l++;
			}
			z += l - 1;
		}
		printf("%lld\n", z);
	}
	return 0;
}