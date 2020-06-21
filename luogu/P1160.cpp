#include <bits/stdc++.h>
using namespace std;
int l[100020];
int r[100020];
bool v[100020];
int n, x, y;
void dfs(int x)
{
	if (x)
	{
		dfs(l[x]);
		if (!v[x])
		{
			printf("%d ", x);
		}
		dfs(r[x]);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		if (y == 0)
		{
			l[i] = l[x];
			l[x] = i;
		}
		else
		{
			r[i] = r[x];
			r[x] = i;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		v[x] = true;
	}
	dfs(1);
	printf("\n");
	return 0;
}