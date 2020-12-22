#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<int> a[50020];
int f[50020][11];
void dfs(int x, int y)
{
	for (int j = 1; j <= 10; j++)
	{
		f[x][j] = j;
	}
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			for (int j = 1; j <= 10; j++)
			{
				int t = 1e9;
				for (int k = 1; k <= 10; k++)
				{
					if (j != k)
					{
						t = min(t, f[i][k]);
					}
				}
				f[x][j] += t;
			}
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
	int t = 1e9;
	for (int k = 1; k <= 10; k++)
	{
		t = min(t, f[1][k]);
	}
	printf("%d\n", t);
	return 0;
}