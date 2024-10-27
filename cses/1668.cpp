#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[100020];
int v[100020];
bool f;
void dfs(int x, int c)
{
	v[x] = c;
	for (int i : a[x])
	{
		if (v[i] == 0)
		{
			dfs(i, 3 - c);
		}
		else if (v[i] != 3 - c)
		{
			f = true;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 0)
		{
			dfs(i, 1);
		}
	}
	if (f)
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", v[i]);
		}
	}
	return 0;
}