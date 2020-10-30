#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int t, n, x;
int c[200020];
ll f[200020];
void R(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int G(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	scanf("%d", &t);
	for (int i = f[0] = 1; i <= 200010; i++)
	{
		f[i] = f[i - 1] * i % mod;
	}
	for (int tt = 0; tt < t; tt++)
	{
		memset(c, 0, sizeof c);
		ll z = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			R(x, 1);
			z = (z + (x - G(x)) * f[n - i]) % mod;
		}
		printf("%lld\n", z);
	}
	return 0;
}