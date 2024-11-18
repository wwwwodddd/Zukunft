#include <bits/stdc++.h>
using namespace std;
const int c = 1000005, mod = 998244353;
int t, n;
long long a[c];
long long p[c];
int main()
{
	p[0] = p[1] = 1;
	for (int i = 2; i < c; i++)
	{
		p[i] = 2 * p[i - 1] % mod;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		a[n] = 0;
		int pos = 0;
		for (int i = 0; i <= n; i++)
		{
			if (a[i] != 1)
			{
				pos = i;
				break;
			}
		}
		long long pp = 0;
		for (int i = 1; i <= pos; i += 2)
		{
			pp = (pp + p[i]) % mod;
		}
		long long xo = pos % 2, z = 0;
		for (int i = pos; i <= n; i++)
		{
			xo ^= a[i];
			if (xo == 0)
			{
				z = (z + p[pos + n - i]) % mod;
			}
			if (xo > 1 && i <= n)
			{
				z = (z + pp * p[n - i]) % mod;
			}
		}
		cout << z << endl;
	}
	return 0;
}