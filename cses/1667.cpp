#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[1000020];
queue<int> q;
int d[1000020];
int f[1000020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(d, -1, sizeof d);
	d[n] = 1;
	q.push(n);
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < a[u].size(); i++)
		{
			int e = a[u][i];
			if (d[e] == -1)
			{
				d[e] = d[u] + 1;
				f[e] = u;
				q.push(e);
			}
		}
	}
	if (d[1] == -1)
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		printf("%d\n", d[1]);
		for (int i = 1; i != n; i = f[i])
		{
			printf("%d ", i);
		}
		printf("%d\n", n);
	}
	return 0;
}