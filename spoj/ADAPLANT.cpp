#include <bits/stdc++.h>
using namespace std;
int a[100020];
int q[100020], b, f;
int u[100020];
int t, n, m;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		m = min(n, m + 2);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		b = f = 0;
		for (int i = 1; i <= n; i++)
		{
			while (b < f && a[q[f - 1]] >= a[i])
			{
				f--;
			}
			q[f++] = i;
			while (q[b] <= i - m)
			{
				b++;
			}
			if (i >= m)
			{
				u[i] = a[q[b]];
			}
		}
		b = f = 0;
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			while (b < f && a[q[f - 1]] <= a[i])
			{
				f--;
			}
			q[f++] = i;
			while (q[b] <= i - m)
			{
				b++;
			}
			if (i >= m)
			{
				z = max(z, a[q[b]] - u[i]);
			}
		}
		printf("%d\n", z);
	}
	return 0;
}