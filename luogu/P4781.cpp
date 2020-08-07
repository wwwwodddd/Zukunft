#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, k, z;
int x[2020];
int y[2020];
int inv(int x)
{
	return x == 1 ? 1 : (long long)(mod - mod / x) * inv(mod % x) % mod;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < n; i++)
	{
		long long a = y[i], b = 1;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				a = a * (mod + k - x[j]) % mod;
				b = b * (mod + x[i] - x[j]) % mod;
			}
		}
		z = (z + a * inv(b)) % mod;
	}
	printf("%d\n", z);
	return 0;
}