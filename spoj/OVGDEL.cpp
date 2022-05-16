#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[10020];
int c[1000020];
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			c[a[i]]++;
		}
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			c[a[i]]--;
			for (long long j = 1; j < 1000020; j *= a[i])
			{
				if (c[j])
				{
					z++;
					break;
				}
				if (a[i] == 1)
				{
					break;
				}
			}
			c[a[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			c[a[i]]--;
		}
		printf("Case %d: %d\n", tt, z);
	}
	return 0;
}