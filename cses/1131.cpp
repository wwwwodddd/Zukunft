#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[200020];
int n, x, y;
int d[200020];
void dfs(int x, int y)
{
	d[x] = d[y] + 1;
	for (pair<int, int> i : a[x])
	{
		if (i.first != y)
		{
			dfs(i.first, x);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, 1));
		a[y].push_back(make_pair(x, 1));
	}
	dfs(1, 0);
	int s = max_element(d + 1, d + 1 + n) - d;
	dfs(s, 0);
	printf("%d\n", *max_element(d + 1, d + 1 + n) - 1);
	return 0;
}