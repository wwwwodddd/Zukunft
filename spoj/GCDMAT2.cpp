#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n, m, a, b, c, d;
int pp[100000], pc;
int f[1000020];
int v[1000020];
double inv[1000020];
int read()
{
	int n=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		;
	for(;isdigit(c);c=getchar())
		n=n*10+c-'0';
	return n;
}
int main()
{
	t = read();
	n = read();
	m = read();
	n = max(n, m);
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			pp[pc++] = i;
			v[i] = i;
		}
		for (int j = 0; j < pc && i * pp[j] <= n; j++)
		{
			v[i * pp[j]] = pp[j];
			if (v[i] == pp[j])
			{
				break;
			}
		}
	}
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] != v[i / v[i]])
		{
			f[i] = f[i / v[i]] * (v[i] - 1);
		}
		else
		{
			f[i] = f[i / v[i]] * v[i];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		inv[i] = 1. / i * (1 + 1e-15);
		f[i] = f[i] + f[i - 1];
		if (f[i] >= p)
		{
			f[i] -= p;
		}
	}
	while (t--)
	{
		a = read() - 1;
		b = read() - 1;
		c = read();
		d = read();
		long long z = 0, s = sqrt(max(c, d));
		for (int j = 1; j <= s; j++)
		{
			long long ff = f[j] - f[j - 1];
			z += ff * (int(c * inv[j]) - int(a * inv[j])) * (int(d * inv[j]) - int(b * inv[j])) % p;
		}
		int aa, bb, cc, dd, aaa = 0, bbb = 0, ccc = 0, ddd = 0;
		for (int j = s + 1; j <= c && j <= d; j++)
		{
			if (j > aaa)
			{
				aa = a * inv[j];
				aaa = aa ? a * inv[aa] : 2e9;
			}
			if (j > bbb)
			{
				bb = b * inv[j];
				bbb = bb ? b * inv[bb] : 2e9;
			}
			if (j > ccc)
			{
				cc = c * inv[j];
				ccc = c * inv[cc];
			}
			if (j > ddd)
			{
				dd = d * inv[j];
				ddd = d * inv[dd];
			}
			int l = min(min(aaa, bbb), min(ccc, ddd));
			long long ff = f[l] - f[j - 1];
			z += ff * (cc - aa) * (dd - bb);
			j = l;
		}
		z %= p;
		if (z < 0)
		{
			z += p;
		}
		printf("%lld\n", z);
	}
	return 0;
}