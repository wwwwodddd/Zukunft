#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200020];
long long b[200020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &b[i]);
	}
	for (int i = 0; i < m; i++)
	{
		long long h = 0;
		for (int j = 0; j < n; j++)
		{
			long long t = max(min(a[j], b[i]) - h, 0LL);
			h += t;
			a[j] += t;
			if (h == b[i])
			{
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%lld\n", a[i]);
	}
	return 0;
}