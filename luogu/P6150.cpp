#include <bits/stdc++.h>
using namespace std;
int n;
int w[10020];
int c[2], s[2];
vector<int> a[10020];
void dfs(int x, int y, int d)
{
	s[d] = (s[d] + w[x]) % 12;
	c[d]++;
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x, d ^ 1);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0, 0);
	if (s[0] == s[1])
	{
		printf("%d\n", n);
	}
	else if ((s[0] + 1) % 12 == s[1])
	{
		printf("%d\n", c[1]);
	}
	else if ((s[1] + 1) % 12 == s[0])
	{
		printf("%d\n", c[0]);
	}
	else
	{
		printf("0\n");
	}
	return 0;
}