#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int p = 998244353;
int v[N + 10];
int f[N + 10];
long long g[N + 10];
vector<int> d[N + 10];
int n;
int a[N + 10];
int main()
{
	for (int i = 2; i <= N; i++)
	{
		if (v[i] == 0)
		{
			for (int j = i; j <= N; j += i)
			{
				v[j] = i;
			}
		}
	}
	f[1] = -1;
	for (int i = 2; i <= N; i++)
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
	for (int i = 2; i <= N; i++)
	{
		if (f[i] != 0)
		{
			for (int j = i; j <= N; j += i)
			{
				d[j].push_back(i);
			}
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= N; i++)
	{
		if (a[1] % i == 0)
		{
			g[i] = (f[i] + p) % p;
		}
	}
	for (int i = 2; i < n; i++)
	{
		int h = 0;
		for (int j : d[a[i]])
		{
			h = (h + g[j]) % p;
		}
		if (h < 0)
		{
			h += p;
		}
		for (int j : d[a[i]])
		{
			g[j] = (g[j] + f[j] * h + p) % p;
		}
	}
	int z = 0;
	for (int i = 2; i <= N; i++)
	{
		if (a[n] % i == 0)
		{
			z = (z + g[i] + p) % p;
		}
	}
	printf("%d\n", z);
	return 0;
}