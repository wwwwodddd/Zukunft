#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[200020];
int v[200020];
void dfs(int x)
{
	v[x] = 1;
	for (int i : a[x])
	{
		if (!v[i])
		{
			printf("%d %d\n", x, i);
			dfs(i);
		}
	}
}
void bfs(int x)
{
	memset(v, 0, sizeof v);
	queue<int> q;
	q.push(x);
	v[x] = 1;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int i : a[u])
		{
			if (!v[i])
			{
				printf("%d %d\n", u, i);
				q.push(i);
				v[i] = 1;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	bfs(1);
	return 0;
}
