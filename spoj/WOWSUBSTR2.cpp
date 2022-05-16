#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[500020];
int v[1000020];
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int z = 0;
		for (int i = 0, j = 0; i < n; v[a[i++]] = 0)
		{
			while (j < n && v[a[j]] == 0)
			{
				v[a[j++]] = 1;
			}
			z = (z + (j - i) * (j - i + 1LL) / 2) % 100007;
		}
		printf("Case %d: %d\n", tt, z);
	}
	return 0;
}