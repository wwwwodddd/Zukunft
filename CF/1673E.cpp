#include <bits/stdc++.h>
using namespace std;
int n, k;
int b[1050000];
int z[1050000];
int C(int n, int m)
{
	return (n & m) == m;
}
map<pair<int, int>, int> g;
int G(int n, int m) // >= m
{
	m = max(m, 0);
	pair<int, int> u = make_pair(n, m);
	if (g.find(u) == g.end())
	{
		int s = 0;
		for (int i = m; i <= n; i++)
		{
			s = (s + C(n, i)) % 2;
		}
		g[u] = s;
	}
	return g[u];
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		long long x = b[i];
		int j = i;
		while (x < (1 << 20))
		{
			int u = n - 1 - (j - i);
			int v = k;
			if (i > 1)
			{
				u--;
				v--;
			}
			if (j < n)
			{
				u--;
				v--;
			}
			if (G(u, v))
			{
				// cout << i << " " << j << " " << x << " " << u << " " << v << " " << G(u, v) << endl;
				z[x] ^= 1;
			}
			if (j < n)
			{
				x *= 1 << b[++j];
			}
			else
			{
				break;
			}
		}
	}
	int l = (1 << 20) - 1;
	while (l > 0 && z[l] == 0)
	{
		l--;
	}
	for (int i = l; i >= 0; i--)
	{
		printf("%d", z[i]);
	}
	printf("\n");
	return 0;
}