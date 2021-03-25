#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, s;
char c[1000020];
int pw(int x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main()
{
	scanf("%d%s", &n, c);
	int z = 1, y = 1;
	for (int i = 0; i < 2 * n; i++)
	{
		if ((c[i] == '(' ? --s : ++s) == 0)
		{
			z = z * 2 % p;
		}
	}
	for (int i = 0; i < n; i++)
	{
		z = (long long)z * (i + 1) % p;
		y = (long long)y * (n + i + 1) % p;
	}
	printf("%lld\n", (long long)z * pw(y, p - 2) % p);
	return 0;
}