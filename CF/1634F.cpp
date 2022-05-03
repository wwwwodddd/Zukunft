#include <bits/stdc++.h>
using namespace std;
int n, q, mod;
int a[300020];
int b[300020];
long long c[300020];
long long d[300020];
int f[300020];
int main()
{
	scanf("%d%d%d", &n, &q, &mod);
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = (a[i] - b[i] + mod) % mod;
	}
	for (int i = 0; i < q; i++)
	{
		char o;
		int l, r;
		scanf(" %c%d%d", &o, &l, &r);
		r++;
		if (o == 'A')
		{
			c[l] += f[1];
			d[l] += f[0];

			c[r] -= f[r - l + 1];
			d[r] -= f[r - l];
		}
		else
		{
			c[l] -= f[1];
			d[l] -= f[0];

			c[r] += f[r - l + 1];
			d[r] += f[r - l];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		c[i] = (c[i] % mod + mod) % mod;
		d[i] = (d[i] % mod + mod) % mod;
		a[i] = (a[i] + c[i]) % mod;
		c[i + 1] += c[i] + d[i];
		d[i + 1] += c[i];
	}
	int f = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != 0)
		{
			f = 0;
			break;
		}
	}
	puts(f ? "YES" : "NO");
	return 0;
}