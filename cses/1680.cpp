#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[1000020];
queue<int> q;
int d[1000020];
int e[1000020];
int f[1000020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[y].push_back(x);
		e[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (e[i] == 0)
		{
			q.push(i);
		}
	}
	d[n] = 1;
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		for (int i : a[u])
		{
			if (d[u] > 0 && d[i] < d[u] + 1)
			{
				d[i] = d[u] + 1;
				f[i] = u;
			}
			if (!--e[i])
			{
				q.push(i);
			}
		}
	}
	if (d[1] == 0)
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
