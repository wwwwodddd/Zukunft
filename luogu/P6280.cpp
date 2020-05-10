#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, mod;
int p[10020], pc;
int isPrime(int x)
{
	if (x < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
ll f[10020];
int main()
{
	cin >> n >> mod;
	for (int i = 1; i <= n; i++)
	{
		if (isPrime(i))
		{
			p[pc++] = i;
		}
	}
	for (int i = 0; i <= n; i++)
	{
		f[i] = 1;
	}
	for (int i = 0; i < pc; i++)
	{
		for (int j = n; j > 0; j--)
		{
			for (int k = p[i]; k <= j; k *= p[i])
			{
				f[j] = (f[j] + f[j - k] * k) % mod;
			}
		}
	}
	printf("%lld\n", f[n]);
	return 0;
}