#include <bits/stdc++.h>
using namespace std;
int n, x;
map<int, int> g;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		g[x]++;
	}
	int z = n;
	while (g.size() > 0)
	{
		if (g.begin()->second == 0)
		{
			g.erase(g.begin());
			continue;
		}
		int u = g.begin()->first;
		int v = g.begin()->second;
		int w = 1;
		g.begin()->second--;
		while (true)
		{
			if (v > g[u + 1])
			{
				z = min(z, w);
				break;
			}
			else
			{
				v = g[++u]--;
				w++;
			}
		}
	}
	cout << z << endl;
	return 0;
}