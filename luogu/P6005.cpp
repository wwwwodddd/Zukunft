#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int w[1020];
int d[1020][1020];
vector<int> a[1020];
priority_queue<pair<int, int> > q[1020];
int main()
{
	cin >> n >> m >> c;
	int l = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		l = max(l, w[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y;
		a[x].push_back(y);
	}
	q[0].push(make_pair(0, 1));
	for (int x = 0; x < 1000; x++)
	{
		while (q[x].size() > 0)
		{
			int z = q[x].top().first;
			int y = q[x].top().second;
			q[x].pop();
			if (z != d[x][y])
			{
				continue;
			}
			for (int i : a[y])
			{
				if (d[x + 1][i] < d[x][y] + w[i])
				{
					d[x + 1][i] = d[x][y] + w[i];
					q[x + 1].push(make_pair(d[x + 1][i], i));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 1001; i++)
	{
		ans = max(ans, d[i][1] - c * i * i);
	}
	cout << ans << endl;
	return 0;
}