#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[300020];
int x[50];
int v[50];
long long e[50];
int f[1048577];
int F(long long s)
{
	if (s < 1 << 20 && f[s] != -1)
	{
		return f[s];
	}
	int p = 63 - __builtin_clzll(s);
	int r = F(s ^ (1LL << p));
	if (v[p] == 0)
	{
		r = max(r, F((s ^ (1LL << p)) & ~e[p]) + x[p]);
	}
	if (s < 1 << 20)
	{
		f[s] = r;
	}
	return r;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		c[i]--;
	}
	int z = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x[i]);
		z += x[i];
	}
	v[c[1]] = 1;
	v[c[n]] = 1;
	for (int i = 1; i < n; i++)
	{
		if (c[i] == c[i + 1])
		{
			v[c[i]] = 1;
		}
		else
		{
			e[c[i]] |= 1LL << c[i + 1];
			e[c[i + 1]] |= 1LL << c[i];
		}
	}
	memset(f, -1, sizeof f);
	f[0] = 0;
	printf("%d\n", z - F((1LL << m) - 1));
	return 0;
}