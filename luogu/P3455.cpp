#include <bits/stdc++.h>
using namespace std;
const int n = 50010;
int q, a, b, d;
int f[50020];
int v[50020];
int p[50020], pc;
int main()
{
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			v[i] = i;
			p[pc++] = i;
		}
		for (int j = 0; j < pc && i * p[j] <= n; j++)
		{
			v[i * p[j]] = p[j];
			if (v[i] == p[j])
			{
				break;
			}
		}
	}
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == v[i / v[i]])
		{
			f[i] = 0;
		}
		else
		{
			f[i] = -f[i / v[i]];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] += f[i - 1];
	}
	scanf("%d", &q);
	for (int qq = 0; qq < q; qq++)
	{
		scanf("%d%d%d", &a, &b, &d);
		a /= d;
		b /= d;
		long long z = 0;
		for (long long l = 1, r; l <= a && l <= b; l = r + 1)
		{
			r = min(a / (a / l), b / (b / l));
			z += (f[r] - f[l - 1]) * (a / l) * (b / l);
		}
		printf("%lld\n", z);
	}
	return 0;
}