#include <bits/stdc++.h>
using namespace std;
long long v[70], x, z;
bool ins(long long x)
{
	for (int i = 62; i >= 0; i--)
	{
		if (x >> i & 1)
		{
			if (!v[i])
			{
				v[i] = x;
				return true;
			}
			x ^= v[i];
		}
	}
	return false;
}
int n;
pair<int, long long> a[1020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%d", &a[i].second, &a[i].first);
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		if (ins(a[i].second))
		{
			z += a[i].first;
		}
	}
	printf("%lld\n", z);
	return 0;
}
