#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, r, c;
int s[5020][5020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &r);
		if (r == 0)
		{
			c++;
		}
		else if (0 < r && r <= c)
		{
			s[c][r]++;
			s[c][c + 1]--;
		}
		else if (-c <= r && r < 0)
		{
			s[c][0]++;
			s[c][c + r + 1]--;
		}
	}
	for (int i = 0; i <= c; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			s[i][j + 1] += s[i][j];
		}
	}
	for (int i = c - 1; i >= 0; i--)
	{
		for (int j = 0; j <= c; j++)
		{
			s[i][j] += max(s[i + 1][j], s[i + 1][j + 1]);
		}
	}
	printf("%d\n", s[0][0]);
	return 0;
}