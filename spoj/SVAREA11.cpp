#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y;
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		map<int, int> g;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			g[x]--;
			g[y + 1]++;
		}
		for (auto i: g)
		{
			n += i.second;
			if (n < 0)
			{
				break;
			}
		}
		printf("Plan %d: %s\n", tt, n < 0 ? "No" : "Yes");
	}
	return 0;
}