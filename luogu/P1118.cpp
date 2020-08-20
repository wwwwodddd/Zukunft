#include <bits/stdc++.h>
using namespace std;
int n, s;
int c[13][13];
int a[13];
int v[13];
void dfs(int x, int s)
{
	if (x == n)
	{
		if (s == 0)
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
			}
			exit(0);
		}
		else
		{
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i] && i * c[n-1][x] <= s)
		{
			a[x] = i;
			v[i] = true;
			dfs(x + 1, s - i * c[n-1][x]);
			v[i] = false;
		}
	}
}
int main()
{
	for (int i = 0; i < 12; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	scanf("%d%d", &n, &s);
	dfs(0, s);
	return 0;
}