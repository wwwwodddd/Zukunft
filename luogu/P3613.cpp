#include <bits/stdc++.h>
using namespace std;
int n, o, x, y, z;
map<pair<int, int>, int> g;
int main()
{
	scanf("%*d%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1)
		{
			scanf("%d", &g[{x, y}]);
		}
		else
		{
			printf("%d\n", g[{x, y}]);
		}
	}
	return 0;
}