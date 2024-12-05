#include <bits/stdc++.h>
using namespace std;
int t, a0, a1, b0, b1;
int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
bool ok(int x)
{
	return gcd(x, a0) == a1 && (long long)x / gcd(x, b0) * b0 == b1;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
		int z = 0;
		if (b1 % a1 == 0)
		{
			int c1 = b1 / a1;
			for (int i = 1; i * i <= c1; i++)
			{
				if (c1 % i == 0)
				{
					if (ok(i * a1))
					{
						z++;
					}
					if (i * i < c1 && ok(c1 / i * a1))
					{
						z++;
					}
				}
			}
		}
		printf("%d\n", z);
	}
	return 0;
}