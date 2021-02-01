#include <bits/stdc++.h>
using namespace std;
int n, m, z, w, s, t;
priority_queue<pair<int, int> > q;
int d[2000020];
struct Edge {
	int to;
	int next;
	int w;
} a[6006000];
int h[2002000], tot;
void add(int x, int y, int z) {
	tot++;
	a[tot].next = h[x];
	a[tot].to = y;
	a[tot].w = z;
	h[x] = tot;

	tot++;
	a[tot].next = h[y];
	a[tot].to = x;
	a[tot].w = z;
	h[y] = tot;
}
int main()
{
	scanf("%d%d",&n,&m);
	n--;
	m--;
	if (n == 0 || m == 0)
	{
		z = 1e9;
		for (int i = 0; i < n + m; i++)
		{
			scanf("%d", &w);
			z = min(z, w);
		}
		printf("%d\n", z);
		return 0;
	}
	s = 2 * n * m;
	t = s + 1;
	for (int j = 0; j < m; j++)
	{
		scanf("%d", &w);
		add(s, j, w);
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &w);
			add(n * m + (i - 1) * m + j, i * m + j, w);
		}
	}
	for (int j = 0; j < m; j++)
	{
		scanf("%d", &w);
		add(n * m + (n - 1) * m + j, t, w);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &w);
		add(n * m + i * m, t, w);
		for (int j = 1; j < m; j++)
		{
			scanf("%d", &w);
			add(i * m + j - 1, n * m + i * m + j, w);
		}
		scanf("%d", &w);
		add(s, i * m + m - 1, w);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &w);
			add(i * m + j, n * m + i * m + j, w);
		}
	}
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	q.push(make_pair(-d[s], s));
	while (q.size() > 0)
	{
		pair<int, int> u = q.top();
		q.pop();
		for (int i = h[u.second]; i > 0; i = a[i].next)
		{
			if (d[a[i].to] > d[u.second] + a[i].w)
			{
				d[a[i].to] = d[u.second] + a[i].w;
				q.push(make_pair(-d[a[i].to], a[i].to));
			}
		}
	}
	printf("%d\n", d[t]);
	return 0;
}