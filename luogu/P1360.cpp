#include <bits/stdc++.h>
using namespace std;
map<vector<int>, int> g;
int n, m, x, z = 0;
int main()
{
	scanf("%d%d", &n, &m);
	vector<int> a(m);
	g[a] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		for (int j = 0; j < m; j++)
		{
			a[j] += x >> j & 1;
		}
		for (int j = 0; j < m; j++)
		{
			a[j] -= a[m - 1];
		}
		if (g.find(a) != g.end())
		{
			z = max(z, i - g[a]);
		}
		else
		{
			g[a] = i;
		}
	}
	printf("%d\n", z);
	return 0;
}