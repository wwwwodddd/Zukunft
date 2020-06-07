#include <bits/stdc++.h>
using namespace std;
int n, m, t, x, y;
int c[310][310];
int d[310][310];
int dx[] = {1, -1, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0};
int bfs()
{
	memset(d, -1, sizeof d);
	d[0][0] = 0;
	queue<int> q;
	q.push(0);
	q.push(0);
	while (q.size()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && d[x][y] + 1 < c[nx][ny] && d[nx][ny] == -1) {
				d[nx][ny] = d[x][y] + 1;
				q.push(nx);
				q.push(ny);
				if (c[nx][ny] == 0x3f3f3f3f)
				{
					return d[nx][ny];
				}
			}
		}
	}
	return -1;
}
int main() {
	memset(c, 0x3f, sizeof c);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> t;
		for (int j = 0; j < 5; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && ny >= 0)
			{
				c[nx][ny] = min(c[nx][ny], t);
			}
		}
	}
	cout << bfs() << endl;
	return 0;
}