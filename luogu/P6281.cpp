#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<long long, long long> a[100020];
bool check(long long d)
{
	long long re = 0;
	long long s = 0;
	for (int i = 0; i < n; i++)
	{
		s = max(s, a[i].first);
		if (s <= a[i].second)
		{
			long long u = (a[i].second - s) / d + 1;
			re += u;
			s += u * d;
		}
	}
	return re >= m;
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	long long L = 0;
	long long R = 2e18;
	while (L < R - 1)
	{
		long long M = (L + R) / 2;
		if (check(M))
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	printf("%lld\n", L);
	return 0;
}