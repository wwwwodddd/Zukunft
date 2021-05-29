#include <bits/stdc++.h>
using namespace std;
int n;
char s[320][320];
int ul[320][320];
int ur[320][320];
long long ans;
bool in(int x, int y)
{
	return 0 < x && x <= n && 0 < y && y <= n;
}
int UL(int x, int y)
{
	int d = max(x - n, y - n);
	if (d > 0)
	{
		x -= d;
		y -= d;
	}
	if (x < 0 || y < 0)
	{
		return 0;
	}
	return ul[x][y];
}
int UR(int x, int y)
{
	int d = max(x - n, 1 - y);
	if (d > 0)
	{
		x -= d;
		y += d;
	}
	if (x < 0 || y > n)
	{
		return 0;
	}
	return ur[x][y];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ul[i][j] = ul[i - 1][j - 1] + (s[i][j] == '*');
			ur[i][j] = ur[i - 1][j + 1] + (s[i][j] == '*');
		}
	}
	for (int x1 = 1; x1 <= n; x1++)
	{
		for (int y1 = 1; y1 <= n; y1++)
		{
			if (s[x1][y1] != '*')
			{
				continue;
			}
			for (int k = 1; k <= n; k++)
			{
				int x2 = x1 + k;
				int y2 = y1 - k;
				if (!in(x2, y2))
				{
					break;
				}
				if (s[x2][y2] == '*')
				{
					ans += UR(x2 + k, y2 + k) - UR(x1 + k - 1, y1 + k + 1);
					ans += UR(x2 - k, y2 - k) - UR(x1 - k - 1, y1 - k + 1);
				}
			}
			for (int k = 1; k <= n; k++)
			{
				int x2 = x1 + k;
				int y2 = y1 + k;
				if (!in(x2, y2))
				{
					break;
				}
				if (s[x2][y2] == '*')
				{
					ans += UL(x2 + k - 1, y2 - k - 1) - UL(x1 + k, y1 - k);
					ans += UL(x2 - k - 1, y2 + k - 1) - UL(x1 - k, y1 + k);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}