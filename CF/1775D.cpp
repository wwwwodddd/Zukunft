#include <bits/stdc++.h>
using namespace std;
int n, x, s, t;
int d[600020];
int f[600020];
vector<int> v[300020];
vector<int> a[600020];
int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= 300000; i++)
	{
		if (v[i].size() == 0)
		{
			for (int j = i; j <= 300000; j += i)
			{
				v[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		for (int j : v[x])
		{
			a[i].push_back(n + j);
			a[n + j].push_back(i);
		}
	}
	scanf("%d%d", &s, &t);
	memset(d, -1, sizeof d);
	queue<int> q;
	q.push(t);
	d[t] = 0;
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		for (int i : a[u])
		{
			if (d[i] == -1)
			{
				d[i] = d[u] + 1;
				f[i] = u;
				q.push(i);
			}
		}
	}
	if (d[s] == -1)
	{
		printf("%d\n", d[s]);
	}
	else
	{
		printf("%d\n", d[s] / 2 + 1);
		for (int i = d[s] / 2 + 1; i > 0; i--)
		{
			printf("%d ", s);
			s = f[f[s]];
		}
		printf("\n");
	}
	return 0;
}