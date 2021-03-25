#include <bits/stdc++.h>
using namespace std;
int n, x, y, c;
vector<int> a[500020];
int s[500020];
void dfs(int x, int y)
{
	if (a[x].size() == 1)
	{
		s[c++] = x;
	}
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", (c + 1) / 2);
	for (int i = 0; i < (c + 1) / 2; i++)
	{
		printf("%d %d\n", s[i], s[i + c / 2]);
	}
	return 0;
}