#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll a[100020], b[100020];
int v[100020];
int c[400], g[400];
ll t[400];
int n, m, q, o;
ll G(int x, int y)
{
	return a[y] + b[y] * x;
}
ll GG(int x, int y)
{
	if (!c[y])
	{
		return -1LL << 60;
	}
	if (x <= t[y])
	{
		return G(x, g[y]);
	}
	int L = y * q, R = min(L + q, n);
	ll z = -1LL << 60;
	for (int i = L; i < R; i++)
	{
		if (v[i])
		{
			ll u = G(x, i);
			if (z < u)
			{
				g[y] = i;
				z = u;
			}
		}
	}
	t[y] = 1LL << 60;
	int j = g[y];
	for (int i = L; i < R; i++)
	{
		if (v[i] && b[i] > b[j])
		{
			t[y] = min(t[y], (a[j] - a[i]) / (b[i] - b[j]));
		}
	}
	return z;
}
int main()
{
	scanf("%d %d", &n, &m);
	q = sqrt(n);
	for (; m--;)
	{
		scanf("%d", &o);
		if (o == 1)
		{
			int t, k, z, s;
			scanf("%d %d %d %d", &t, &k, &z, &s), k--;
			b[k] = z;
			a[k] = s - b[k] * t;
			::t[k / q] = 0;
			if (!v[k])
			{
				c[k / q]++;
				v[k] = 1;
			}
		}
		else
		{
			int t, l, r;
			ll z = -1LL << 60;
			scanf("%d %d %d", &t, &l, &r);
			if (l > r)
			{
				swap(l, r);
			}
			l--;
			if (l / q == r / q)
			{
				for (int i = l; i < r; i++)
				{
					if (v[i])
					{
						z = max(z, G(t, i));
					}
				}
			}
			else
			{
				for (int i = l; i % q; i++)
				{
					if (v[i])
					{
						z = max(z, G(t, i));
					}
				}
				for (int i = (l + q - 1) / q; i < r / q; i++)
				{
					z = max(z, GG(t, i));
				}
				for (int i = r; i-- % q;)
				{
					if (v[i])
					{
						z = max(z, G(t, i));
					}
				}
			}
			if (z == -1LL << 60)
			{
				puts("nema");
			}
			else
			{
				printf("%lld\n", z);
			}
		}
	}
	return 0;
}
