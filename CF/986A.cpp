#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, x, y;
int a[100020];
vector<int> e[100020];
int d[100020][101];
int main()
{
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int c = 1; c <= k; c++)
	{
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == c)
			{
				d[i][c] = 0;
				q.push(i);
			}
			else
			{
				d[i][c] = -1;
			}
		}
		while (q.size())
		{
			int u = q.front();
			q.pop();
			for (int i : e[u])
			{
				if (d[i][c] == -1)
				{
					d[i][c] = d[u][c] + 1;
					q.push(i);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sort(d[i] + 1, d[i] + 1 + k);
		cout << accumulate(d[i] + 1, d[i] + 1 + s, 0) << " ";
	}
	return 0;
}
