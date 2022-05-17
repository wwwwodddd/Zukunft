#include <bits/stdc++.h>
using namespace std;
int n, m, z;
char s[1020];
int d[1020][1020];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<int> q;
int in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main()
{
	cin >> n >> m;
	memset(d, -1, sizeof d);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == '#')
			{
				d[i][j] = 0;
				q.push(i);
				q.push(j);
			}
		}
	}
	while (q.size())
	{
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		z = d[x][y];
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny) && d[nx][ny] == -1)
			{
				d[nx][ny] = d[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	cout << z << endl;
	return 0;
}
