#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, s;
int f[3020];
int a[3020];
long long z;
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == s)
		{
			z = (z + (i + 1) * (n - i)) % p;
		}
		if (a[i] <= s)
		{
			z = (z + (long long)f[s - a[i]] * (n - i)) % p;
		}
		for (int k = s; k >= a[i]; k--)
		{
			f[k] = (f[k] + f[k - a[i]]) % p;
		}
		f[a[i]] = (f[a[i]] + i + 1) % p;
	}
	printf("%lld\n", z);
	return 0;
}