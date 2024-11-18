#include <bits/stdc++.h>
using namespace std;
int t, n, m, l;
int a[1000020];
int b[1000020];
int ac[1000020];
int bc[1000020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &n, &m, &l);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &b[i]);
			bc[b[i]]++;
		}
		int s = 0;
		for (int i = 1; i < m; i++)
		{
			s -= min(bc[a[i]], ac[a[i]]);
			ac[a[i]]++;
			s += min(bc[a[i]], ac[a[i]]);
		}
		int z = 0;
		for (int i = m; i <= n; i++)
		{
			s -= min(bc[a[i]], ac[a[i]]);
			ac[a[i]]++;
			s += min(bc[a[i]], ac[a[i]]);
			if (s >= l)
			{
				z++;
			}
			s -= min(bc[a[i - m + 1]], ac[a[i - m + 1]]);
			ac[a[i - m + 1]]--;
			s += min(bc[a[i - m + 1]], ac[a[i - m + 1]]);
		}
		for (int i = 1; i <= m; i++)
		{
			bc[b[i]]--;
		}
		for (int i = n - m + 2; i <= n; i++)
		{
			ac[a[i]]--;
		}
		printf("%d\n", z);
	}
	return 0;
}