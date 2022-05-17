#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, ex, ey;
char s[60][60];
int d[60][60];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int> > q;
int main()
{
	cin >> n >> m >> sx >> sy >> ex >> ey;
	sx--;
	sy--;
	ex--;
	ey--;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	memset(d, -1, sizeof d);
	d[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (q.size())
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if (s[nx][ny] == '.' && d[nx][ny] == -1)
			{
				d[nx][ny] = d[u.first][u.second] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	cout << d[ex][ey] << endl;
	return 0;
}
