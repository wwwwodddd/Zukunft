#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, l, r = 1e6;
int v[1000020];
int u[1000020];
int c[1000020];
int s[1000020];
long long z;
int main()
{
	v[1] = s[1] = z = 1;
	for (int i = 2; i <= r; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
		if (!u[i])
		{
			for (int j = i; j <= r; j += i)
			{
				u[j] = i;
			}
		}
		for (int j = i; j > 1; j /= u[j])
		{
			z = z * v[c[u[j]] + 1] % p;
			z = z * (++c[u[j]] + 1) % p;
		}
		s[i] = (s[i - 1] + z) % p;
	}
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", (s[r] + p - s[l - 1]) % p);
	}
	return 0;
}