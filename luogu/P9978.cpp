#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int a[500020];
int b[500020];
int p[500020];
int c[500020];
int v[500020];
void kao()
{
	memset(p, -1, sizeof p);
	memset(c, 0, sizeof c);
	memset(v, 0, sizeof v);
	for (int i = 0; i < m; i++)
	{
		v[a[i]] = 1;
		p[a[i]] = i;
	}
	int zz = 0;
	for (int i = 0; i < m; i++)
	{
		v[b[i]] = 1;
		if (p[b[i]] != -1)
		{
			int d = (i + m - p[b[i]]) % m;
			zz = max(zz, ++c[d]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
		{
			zz++;
		}
	}
	z = max(z, zz);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	kao();
	reverse(b, b + m);
	kao();
	printf("%d\n", z);
	return 0;
}