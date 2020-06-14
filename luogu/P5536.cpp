#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100020];
int c[100020];
int d[100020];
int main()
{
	scanf("%d%d", &n, &m);
	m = n - m;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
		c[x]++;
		c[y]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 1)
		{
			d[i] = 1;
			q.push(i);
		}
	}
	while (q.size())
	{
		int u = q.front();
		q.pop();
		if (!--m)
		{
			printf("%d\n", d[u]);
			break;
		}
		for (int i: a[u])
		{
			if (--c[i] == 1)
			{
				d[i] = d[u] + 1;
				q.push(i);
			}
		}
	}
	return 0;
}