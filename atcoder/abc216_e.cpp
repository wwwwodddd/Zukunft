#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200020];
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i > 0; i--)
	{
		long long t = (long long)(a[i] - a[i - 1]) * (n - i + 1);
		if (t >= m)
		{
			long long x = m / (n - i + 1);
			long long y = m % (n - i + 1);
			z += (long long)(a[i] + a[i] - x + 1) * x / 2 * (n - i + 1);
			z += (long long)(a[i] - x) * y;
			break;
		}
		else
		{
			m -= t;
			z += (long long)(a[i] + a[i - 1] + 1) * (a[i] - a[i - 1]) / 2 * (n - i + 1);
		}
	}
	printf("%lld\n", z);
	return 0;
}