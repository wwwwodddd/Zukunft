#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[200020];
int v[200020];
vector<pair<int, int> > a[200020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		l--;
		a[l].push_back(make_pair(r, x));
	}
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		a[i].push_back(make_pair(i + 1, 0));
		a[i + 1].push_back(make_pair(i, -1));
		q.push(i);
		v[i] = 1;
	}
	while (q.size())
	{
		int u = q.front();
		q.pop();
		v[u] = 0;
		for (pair<int, int> i: a[u])
		{
			if (d[i.first] < d[u] + i.second)
			{
				d[i.first] = d[u] + i.second;
				if (!v[i.first])
				{
					q.push(i.first);
					v[i.first] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", d[i] - d[i - 1], i == n ? '\n' : ' ');
	}
	return 0;
}