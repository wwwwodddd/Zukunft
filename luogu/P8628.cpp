#include <bits/stdc++.h>
using namespace std;
int n, ax, ay, bx, by;
char s[120][120];
int d[120][120];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool can(int x, int y, int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= n || ny >= n)
	{
		return false;
	}
	if (isalpha(s[x][y]) || isalpha(s[nx][ny]))
	{
		return true;
	}
	return s[x][y] == s[nx][ny];
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
			if (s[i][j] == 'A')
			{
				ax = i;
				ay = j;
			}
			else if (s[i][j] == 'B')
			{
				bx = i;
				by = j;
			}
			else
			{
				if ((i + j) & 1)
				{
					s[i][j] ^= 6;
				}
			}
		}
	}
	memset(d, -1, sizeof d);
	d[ax][ay] = 0;
	queue<int> q;
	q.push(ax);
	q.push(ay);
	while (q.size())
	{
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (can(x, y, nx, ny) && d[nx][ny] == -1)
			{
				d[nx][ny] = d[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	cout << d[bx][by] << endl;
	return 0;
}
