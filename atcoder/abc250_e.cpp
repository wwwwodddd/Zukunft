#include <bits/stdc++.h>
using namespace std;
int n, q;
long long x, y;
long long a[200020];
long long b[200020];
int main()
{
	scanf("%d", &n);
	set<int> ta, tb;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &x);
		if (!ta.count(x))
		{
			long long y = x * x * x - x * x + x;
			y ^= y >> 15;
			a[i] = a[i - 1] ^ y;
			ta.insert(x);
		}
		else
		{
			a[i] = a[i - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &x);
		if (!tb.count(x))
		{
			long long y = x * x * x - x * x + x;
			y ^= y >> 15;
			b[i] = b[i - 1] ^ y;
			tb.insert(x);
		}
		else
		{
			b[i] = b[i - 1];
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%lld%lld", &x, &y);
		puts(a[x] == b[y] ? "Yes" : "No");
	}
	return 0;
}