#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int p[52], pc, n, y, z;
long long v[52], x;
bool ins(long long x)
{
	for (int i = 50; i >= 0; i--)
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
int main()
{
	while (scanf("%d", &n), n)
	{
		pc = 0;
		z = 1;
		memset(v, 0, sizeof v);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &y);
			x = 0;
			for (int i = 0; i < pc; i++)
			{
				while (y % p[i] == 0)
				{
					x ^= 1LL << i;
					y /= p[i];
				}
			}
			for (int i = 2; i * i <= y; i++)
			{
				if (y % i == 0)
				{
					while (y % i == 0)
					{
						x ^= 1LL << pc;
						y /= i;
					}
					p[pc++] = i;
				}
			}
			if (y > 1)
			{
				x ^= 1LL << pc;
				p[pc++] = y;
			}
			if (!ins(x))
			{
				z = z * 2 % mod;
			}
		}
		printf("%d\n", z - 1);
	}
	return 0;
}