#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m;
long long a[200020]; 
long long c0[200020];
long long c1[200020];
long long c2[200020];
void change(int x, long long y)
{
	y %= p;
	if (y < 0)
	{
		y += p;
	}
	for (int i = x; i <= n; i += i & -i)
	{
		c0[i] = (c0[i] + y) % p;
		c1[i] = (c1[i] + y * x) % p;
		c2[i] = (c2[i] + y * x % p * x) % p;
	}
}
long long query(int x)
{
	long long re0 = 0;
	long long re1 = 0;
	long long re2 = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re0 = (re0 + c0[i]) % p;
		re1 = (re1 + c1[i]) % p;
		re2 = (re2 + c2[i]) % p;
	}
	long long re = (re0 * (x + 1) % p * (x + 2) % p - re1 * (2 * x + 3) % p + re2) % p;
	if (re < 0)
	{
		re += p;
	}
	if (re & 1)
	{
		re += p;
	}
	return re / 2;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		change(i, a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		scanf("%d", &o);
		if (o == 2)
		{
			scanf("%d", &x);
			printf("%lld\n", query(x));
		}
		else
		{
			scanf("%d%d", &x, &y);
			change(x, y - a[x]);
			a[x] = y;
		}
	}
	return 0;
}
