#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int v[1000020];
int z[2000020];
int t, n, l, r;
int main()
{
	scanf("%d", &t);
	v[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &n, &l, &r);
		int c = 1;
		for (int i = 0; i <= n; i++)
		{
			z[2 * i] = c;
			c = (long long)c * (n - i) % p * v[i + 1] % p;
		}
		for (int i = l + n; i <= r + n; i++)
		{
			printf("%d ", z[i]);
		}
		printf("\n");
	}
	return 0;
}