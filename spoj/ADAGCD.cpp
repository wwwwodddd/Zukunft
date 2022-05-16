#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
const int N = 10000000;
int v[N + 20];
int n, m, x;
map<int, int> g;
int main()
{
	for (int i = 2; i <= N; i++)
	{
		if (!v[i])
		{
			for (int j = i; j <= N; j += i)
			{
				v[j] = i;
			}
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		map<int, int> f;
		for (int i = 0; i < m; i++)
		{
			for (scanf("%d", &x); x > 1; x /= v[x])
			{
				f[v[x]]++;
			}
		}
		if (i)
		{
			for (auto &i: f)
			{
				i.second = min(i.second, g[i.first]);
			}
		}
		g.swap(f);
	}
	long long z = 1;
	for (auto &i: g)
	{
		for (int j = 0; j < i.second; j++)
		{
			z = z * i.first % p;
		}
	}
	printf("%lld\n", z);
	return 0;
}