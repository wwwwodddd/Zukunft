#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[3020];
int d0[3020];
int d1[3020];
int d2[3020];
void bfs(int x, int d[3020])
{
	memset(d, 0x3f, sizeof d0);
	queue<int> q;
	q.push(x);
	d[x] = 0;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int i : a[u])
		{
			if (d[i] > d[u] + 1)
			{
				q.push(i);
				d[i] = d[u] + 1;
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int s1, t1, s2, t2;
	cin >> s1 >> t1 >> s2 >> t2;
	bfs(1, d0);
	bfs(s1, d1);
	bfs(s2, d2);
	int z = m + 1;
	for (int i = 1; i <= n; i++)
	{
		if (d0[i] + d1[i] <= t1 && d0[i] + d2[i] <= t2)
		{
			z = min(z, d0[i] + d1[i] + d2[i]);
		}
	}
	cout << m - z << endl;
	return 0;
}