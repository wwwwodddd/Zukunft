#include <bits/stdc++.h>
using namespace std;
int t, n, d, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d", &n, &d);
		map<int, int> g;
		long long z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (g.count(x - d))
			{
				z += g[x - d];
			}
			if (g.count(x + d))
			{
				z += g[x + d];
			}
			g[x]++;
		}
		printf("Case %d: %lld\n", tt, z);
	}
	return 0;
}