#include <bits/stdc++.h>
using namespace std;
int a[300020];
int b[300020];
pair<int, int> e[600020];
int n, m, c, r;
long long z;
int main()
{
	scanf("%d%d%d%d", a, b, &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
	}
	n++;
	m++;
	sort(a, a + n + 1);
	sort(b, b + m + 1);
	for (int i = 0; i < n; i++)
	{
		e[i] = make_pair(a[i + 1] - a[i], 0);
	}
	for (int i = 0; i < m; i++)
	{
		e[i + n] = make_pair(b[i + 1] - b[i], 1);
	}
	sort(e, e + n + m);
	for (int i = 0; i < n + m; i++)
	{
		if (e[i].second)
		{
			if (!c || !r)
			{
				z += (long long)(n - 1) * e[i].first;
			}
			else
			{
				z += (long long)(n - c) * e[i].first;
			}
			r++;
		}
		else
		{
			if (!c || !r)
			{
				z += (long long)(m - 1) * e[i].first;
			}
			else
			{
				z += (long long)(m - r) * e[i].first;
			}
			c++;
		}
	}
	printf("%lld\n", z);
	return 0;
}