#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100020];
vector<int> a[100020];
int f[100020][20];
int c[100020];
int d[100020];
void dfs(int x, int y)
{
	f[x][0] = y;
	d[x] = d[y] + 1;
	c[x] = c[y] + (s[x] == 'G');
	for (int i = 1; i < 20; i++)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
}
int lca(int x, int y)
{
	if (d[x] < d[y])
	{
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 20; i++)
	{
		if (dd >> i & 1)
		{
			x = f[x][i];
		}
	}
	if (x == y)
	{
		return x;
	}
	for (int i = 20 - 1; i >= 0; i--)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		char o[2];
		scanf("%d%d%s", &x, &y, o);
		int l = lca(x, y);
		int dxy = d[x] + d[y] - 2 * d[l] + 1;
		int cxy = c[x] + c[y] - 2 * c[l] + (s[l] == 'G');
		if (o[0] == 'G')
		{
			printf("%d", cxy > 0);
		}
		else
		{
			printf("%d", cxy < dxy);
		}
	}
	printf("\n");
	return 0;
}