#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
vector<int> a[1000020];
int g[1000020];
int s[1000020];
int b[1000020];
int z[1000020];
int v[1000020];
int h[1000020];
int t, n = 1000000;
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
	h[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == v[i / v[i]])
		{
			h[i] = 0;
		}
		else
		{
			h[i] = p - h[i / v[i]];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			a[j].push_back(i);
		}
	}
	int ff = 0;
	for (int i = 1; i <= n; i++)
	{
		ff++;
		for (int j : a[i])
		{
			b[j] = 1;
			ff = (ff + s[j]) % p;
			for (int d : a[j])
			{
				b[j] = (b[j] + s[d]) % p;
			}
			b[j] = (b[j] - g[j] + p) % p;
			g[j] = (g[j] + 2 * b[j] % p) % p;
		}
		for (int j : a[i])
		{
			for (int k : a[j])
			{
				s[j] = (s[j] + 2LL * b[k] * h[j / k]) % p;
			}
		}
		z[i] = ff;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%d\n", z[n]);
	}
	return 0;
}
