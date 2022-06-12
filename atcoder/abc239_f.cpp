#include <bits/stdc++.h>
using namespace std;
int n, m, s, x, y;
int d[200020];
int f[200020];
vector<int> a[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		f[i] = i;
		s += d[i];
	}
	if (s != 2 * n - 2)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		d[x]--;
		d[y]--;
		if (F(x) == F(y) || d[x] < 0 || d[y] < 0)
		{
			puts("-1");
			return 0;
		}
		f[F(x)] = F(y);
	}
	vector<int> p, q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < d[i]; j++)
		{
			a[F(i)].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (F(i) == i)
		{
			if (a[i].size() == 0)
			{
				puts("-1");
				return 0;
			}
			else if (a[i].size() == 1)
			{
				p.push_back(i);
			}
			else
			{
				q.push_back(i);
			}
		}
	}
	while (q.size())
	{
		printf("%d %d\n", a[p.back()].back(), a[q.back()].back());
		p.pop_back();
		a[q.back()].pop_back();
		if (a[q.back()].size() == 1)
		{
			p.push_back(q.back());
			q.pop_back();
		}
	}
	printf("%d %d\n", a[p[0]][0], a[p[1]][0]);
	return 0;
}