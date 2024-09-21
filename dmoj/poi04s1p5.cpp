#include <bits/stdc++.h>
using namespace std;
int n = 50000;
int v[50050];
int p[50050];
int main()
{
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}
		}
	}
	p[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == v[i / v[i]])
		{
			p[i] = 0;
		}
		else
		{
			p[i] = -p[i / v[i]];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		p[i] += p[i - 1];
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		a /= k;
		b /= k;
		int z = 0;
		for (int j = 1; j <= min(a, b); j++)
		{
			int aj = a / j;
			int bj = b / j;
			int l = min(a / aj, b / bj);
			z += (p[l] - p[j - 1]) * bj * aj;
			j = l;
		}
		printf("%d\n", z);
	}
	return 0;
}