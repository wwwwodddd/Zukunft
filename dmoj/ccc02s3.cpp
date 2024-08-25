#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int r, c, n;
string s[400];
char t[30020];
pair<int, int> ok(int x, int y, int d)
{
	if (s[x][y] == 'X')
	{
		return make_pair(-1, -1);
	}
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 'F')
		{
			x += dx[d];
			y += dy[d];
			if (x < 0 || r <= x || y < 0 || c <= y || s[x][y] == 'X')
			{
				return make_pair(-1, -1);
			}
		}
		else if (t[i] == 'L')
		{
			d = (d + 3) % 4;
		}
		else if (t[i] == 'R')
		{
			d = (d + 1) % 4;
		}
	}
	return make_pair(x, y);
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> s[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				pair<int, int> u = ok(i, j, k);
				if (u != make_pair(-1, -1))
				{
					s[u.first][u.second] = '*';
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		cout << s[i] << endl;
	}
	return 0;
}