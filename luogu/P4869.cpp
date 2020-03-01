#include <bits/stdc++.h>
using namespace std;
const int mod = 10086;
long long v[70], x, z, t = 1;
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
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		if (!ins(x))
		{
			t = t * 2 % mod;
		}
	}
	scanf("%lld", &x);
	for (int i = 0, j = 0; i < 62; i++)
	{
		if (v[i])
		{
			if (x >> i & 1)
			{
				z += 1LL << j;
			}
			j++;
		}
	}
	printf("%lld\n", (z % mod * t + 1) % mod);
	return 0;
}
