#include <bits/stdc++.h>
using namespace std;
int t, n, p;
int a[200020];
int e[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &p);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i < n; i++)
		{
			e[i] = p;
		}
		int d = a[1];
		for (int i = 2; i <= n; i++)
		{
			if (a[i] % d == 0)
			{
				e[i - 1] = min(e[i - 1], d);
			}
			else
			{
				d = a[i];
			}
		}
		d = a[n];
		for (int i = n - 1; i > 0; i--)
		{
			if (a[i] % d == 0)
			{
				e[i] = min(e[i], d);
			}
			else
			{
				d = a[i];
			}
		}
		long long s = 0;
		for (int i = 1; i < n; i++)
		{
			s += e[i];
		}
		printf("%lld\n", s);
	}
	return 0;
}