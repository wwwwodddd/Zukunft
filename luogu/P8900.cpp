#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long h[200020], s;
int d[200020];
vector<int> a[200020];
vector<pair<int, long long> > b[200020];
int z;
void dfs(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			if (h[i] > 0)
			{
				b[i].push_back({x, h[i]});
				d[x]++;
			}
			else if (h[i] < 0)
			{
				b[x].push_back({i, -h[i]});
				d[i]++;
			}
			else
			{
				z--;
			}
			h[x] += h[i];
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &h[i]);
		s += h[i];
	}
	assert(s % n == 0);
	s /= n;
	for (int i = 1; i <= n; i++)
	{
		h[i] -= s;
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	z = n - 1;
	dfs(1, 0);
	printf("%d\n", z);
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (auto j : b[u])
		{
			printf("%d %d %lld\n", u, j.first, j.second);
			if (!--d[j.first])
			{
				q.push(j.first);
			}
		}
	}
	return 0;
}