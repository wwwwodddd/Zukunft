#include <bits/stdc++.h>
using namespace std;
int t, m;
long long a, b;
int pw(long long x, long long y)
{
	long long re = 1;
	x %= m;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % m;
		}
		x = x * x % m;
	}
	return re;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld%lld%d", &a, &b, &m);
		a = pw(a, b);
		printf("%lld\n", a ? a : m);
	}
	return 0;
}