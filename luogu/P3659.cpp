#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;
int a[120][120];
int d[120][120];
int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(d, 0x3f, sizeof d);
	int ans = d[0][0];
	d[0][0] = 0;
	s.insert(make_pair(0, 0));
	while(s.size())
	{
		int u = s.begin()->second;
		s.erase(s.begin());
		int x = u / n;
		int y = u % n;
		if (abs(n - x) + abs(n - y) <= 4)
		{
			ans = min(ans, d[x][y] + (abs(n - x) + abs(n - y) - 2) * t);
		}
		for (int k = 0; k < 16; k++)
		{
			int nx = x + k / 4 + k % 4 - 3;
			int ny = y + k / 4 - k % 4;
			if (0 <= nx && nx < n && 0 <= ny && ny < n)
			{
				if (d[nx][ny] > d[x][y] + a[nx][ny] + 3 * t)
				{
					s.erase(make_pair(d[nx][ny], nx * n + ny));
					d[nx][ny] = d[x][y] + a[nx][ny] + 3 * t;
					s.insert(make_pair(d[nx][ny], nx * n + ny));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}