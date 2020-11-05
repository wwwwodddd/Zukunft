#include <bits/stdc++.h>
using namespace std;
int t, n, m, p;
int inv(int x)
{
	return x == 1 ? 1 : (long long)(p - p / x) * inv(p % x) % p;
}
int C(int n, int m)
{
	if (m < 0 || m > n)
	{
		return 0;
	}
	if (n < p)
	{
		long long re = 1;
		for (int i = 0; i < m; i++)
		{
			re = re * (n - i) % p * inv(i + 1) % p;
		}
		return re;
	}
	else
	{
		return C(n % p, m % p) * C(n / p, m / p) % p;
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &n, &m, &p);
		printf("%d\n", C(n + m, m));
	}
	return 0;
}