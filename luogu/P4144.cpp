#include <bits/stdc++.h>
using namespace std;
int n, b, p, x, z;
int pw(int x, int y)
{
	int re = 1 % p;
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
	scanf("%d%d%d", &n, &b, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		z = max(z, x);
	}
	z = z * 2 + 233;
	printf("%d\n", pw(z, b));
	return 0;
}
