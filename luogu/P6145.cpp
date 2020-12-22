#include <bits/stdc++.h>
using namespace std;
int n, m, c, x, y, z;
vector<pair<int, int> > a[100020];
int d[100020];
int in[100020];
queue<int> q;
int main()
{
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
	}
	for (int i = 0; i < c; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		in[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		for (pair<int, int> i: a[u])
		{
			if (d[i.first] < d[u] + i.second)
			{
				d[i.first] = d[u] + i.second;
			}
			if (!--in[i.first])
			{
				q.push(i.first);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", d[i]);
	}
	return 0;
}