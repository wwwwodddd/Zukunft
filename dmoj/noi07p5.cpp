#include <bits/stdc++.h>
using namespace std;
int a[52][52];
int b[52][52];
int r[52], e[6] = {1, 1, 1, 3, 16, 125};
int p = 65521, t, k;
map<int, int> g;
long long n;
void mul(int a[52][52], int b[52][52], int c[52][52])
{
	long long w[52][52] = {};
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			for (int k = 0; k < t; k++)
			{
				w[i][j] += (long long)a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			c[i][j] = w[i][j] % p;
		}
	}
}
void dfs(int x, int y, int z)
{
	if (x == k)
	{
		g[z] = t;
		r[t++] = z;
	}
	else
	{
		for (int i = 0; i <= y; i++)
		{
			dfs(x + 1, max(y, i + 1), z | i << x * 4);
		}
	}
}
void gen()
{
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 1 << k; j++)
		{
			int c[5] = {};
			for (int u = 0; u < k; u++)
			{
				if (j >> u & 1)
				{
					c[r[i] >> 4 * u & 15]++;
				}
			}
			int ok = 1;
			for (int u = 0; u < k; u++)
			{
				if (c[u] > 1)
				{
					ok = 0;
				}
			}
			if (!ok)
			{
				continue;
			}
			if (!c[0])
			{
				int ok = 0;
				for (int u = 1; u < k; u++)
				{
					if ((r[i] >> 4 * u & 15) == (r[i] & 15))
					{
						ok = 1;
					}
				}
				if (!ok)
				{
					continue;
				}
			}
			int w[6] = {}, v[6] = {}, cnt = 0, o = r[i];
			for (int u = 0; u < k; u++)
			{
				w[u] = o & 15;
				o >>= 4;
			}
			for (int u = 0; u < k; u++)
			{
				if (c[r[i] >> 4 * u & 15])
				{
					w[u] = k;
				}
			}
			w[k] = k;
			for (int u = 1; u <= k; u++)
			{
				if (!v[w[u]])
				{
					v[w[u]] = ++cnt;
				}
			}
			int q = 0;
			for (int u = 1; u <= k; u++)
			{
				q = q | (v[w[u]] - 1 << (u - 1 << 2));
			}
			b[i][g[q]]++;
		}
	}
}
int main()
{
	scanf("%d%lld", &k, &n);
	dfs(0, 0, 0);
	gen();
	for (int i = 0; i < t; i++)
	{
		a[0][i] = 1;
		for (int j = 0; j < k; j++)
		{
			int c = 0;
			for (int u = 0; u < k; u++)
			{
				if ((r[i] >> u * 4 & 15) == j)
				{
					c++;
				}
			}
			a[0][i] *= e[c];
		}
	}
	for (n -= k; n; n >>= 1)
	{
		if (n & 1)
		{
			mul(a, b, a);
		}
		mul(b, b, b);
	}
	printf("%d\n", a[0][0]);
}