#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y;
vector<int> a[500020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
		{
			sort(a[i].begin(), a[i].end());
			for (int j : a[i])
			{
				printf("%d ", j);
			}
			printf("\n");
			a[i].clear();
		}
	}
	return 0;
}