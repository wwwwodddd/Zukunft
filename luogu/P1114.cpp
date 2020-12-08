#include <bits/stdc++.h>
using namespace std;
int s, x, z, n;
map<int, int> g;
int main()
{
	scanf("%d", &n);
	g[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s += 2 * x - 1;
		if (g.find(s) == g.end())
		{
			g[s] = i;
		}
		else
		{
			z = max(z, i - g[s]);
		}
	}
	printf("%d\n", z);
	return 0;
}