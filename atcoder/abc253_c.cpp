#include <bits/stdc++.h>
using namespace std;
map<int, int> g;
int q, o, x, c;
int main()
{
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d", &x);
			g[x]++;
		}
		else if (o == 2)
		{
			scanf("%d%d", &x, &c);
			g[x] -= c;
			if (g[x] <= 0)
			{
				g.erase(x);
			}
		}
		else
		{
			printf("%d\n", g.rbegin()->first - g.begin()->first);
		}
	}
	return 0;
}
