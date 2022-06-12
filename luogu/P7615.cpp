#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char s[12][12];
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')
			{
				int c = 0;
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (in(x, y) && s[x][y] == '.')
					{
						c++;
					}
				}
				if (c == 1)
				{
					cout << 1 << endl;
					return 0;
				}
			}
		}
	}
	cout << 0 << endl;
	return 0;
}
