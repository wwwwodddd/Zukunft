#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int a[120][120];
int d[120][120];
set<pair<int, pair<int, int> > > s;
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main()
{
	cin >> n >> m;
	memset(d, 0x3f, sizeof d);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
			{
				d[i][j] = a[i][j];
				s.insert(make_pair(a[i][j], make_pair(i, j)));
			}
		}
	}
	int z = 0;
	while (s.size())
	{
		int e = s.begin()->first;
		int x = s.begin()->second.first;
		int y = s.begin()->second.second;
		s.erase(s.begin());
		z += d[x][y] - a[x][y];
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (in(nx, ny) && d[nx][ny] > max(e, a[nx][ny]))
			{
				s.erase(make_pair(d[nx][ny], make_pair(nx, ny)));
				d[nx][ny] = max(e, a[nx][ny]);
				s.insert(make_pair(d[nx][ny], make_pair(nx, ny)));
			}
		}
	}
	cout << z << endl;
	return 0;
}
