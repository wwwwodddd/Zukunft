#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<int> a[5020];
int d[5020];
int f[5020];
void bfs(int x)
{
	memset(d, -1, sizeof d);
	queue<int> q;
	q.push(x);
	d[x] = 0;
	while (q.size())
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
			else if (i != f[u])
			{
				z = min(z, d[i] + d[u] + 1);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	z = n + 1;
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}
	if (z > n)
	{
		z = -1;
	}
	cout << z << endl;
	return 0;
}