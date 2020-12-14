#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
int n, m, x, y, z = -1;
void dfs(int x, int y, int d)
{
	if (d <= m)
	{
		z++;
		for (int i: a[x])
		{
			if (i != y)
			{
				dfs(i, x, d + 1);
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0, 0);
	printf("%d\n", z);
	return 0;
}