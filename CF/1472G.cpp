#include <bits/stdc++.h>
using namespace std;
int t, n, m;
vector<int> a[200020];
int d[200020];
int o[200020];
int z[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			o[i] = i;
		}
		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
		}
		memset(d, -1, sizeof d);
		d[1] = 0;
		queue<int> q;
		q.push(1);
		while (q.size())
		{
			int u = q.front();
			q.pop();
			for (int i : a[u])
			{
				if (d[i] == -1)
				{
					z[i] = d[i] = d[u] + 1;
					q.push(i);
				}
			}
		}
		sort(o + 1, o + 1 + n, [](int x, int y){return d[x] > d[y];});
		for (int i = 1; i <= n; i++)
		{
			for (int j : a[o[i]])
			{
				if (d[o[i]] < d[j])
				{
					z[o[i]] = min(z[o[i]], z[j]);
				}
				else
				{
					z[o[i]] = min(z[o[i]], d[j]);
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", z[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}