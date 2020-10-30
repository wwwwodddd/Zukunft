#include <bits/stdc++.h>
using namespace std;
int f[100020];
int r[32];
int v[32];
int t, n, m, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &r[i]);
		}
		memset(v, 0, sizeof v);
		for (int i = 1; i < 100010; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i >= r[j])
				{
					v[f[i - r[j]]] = i;
				}
			}
			f[i] = 0;
			while (v[f[i]] == i)
			{
				f[i]++;
			}
		}
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			z ^= f[x];
		}
		puts(z ? "Ada" : "Vinit");
	}
	return 0;
}