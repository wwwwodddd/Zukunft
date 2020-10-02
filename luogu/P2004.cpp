#include <bits/stdc++.h>
using namespace std;
int n, m, c, x, y, z = -1e9;
int s[1020][1020];
int main()
{
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &s[i][j]);
			s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
			if (i >= c && j >= c && z < s[i][j] - s[i-c][j] - s[i][j-c] + s[i-c][j-c])
			{
				x = i;
				y = j;
				z = s[i][j] - s[i-c][j] - s[i][j-c] + s[i-c][j-c];
			}
		}
	}
	printf("%d %d\n", x - c + 1, y - c + 1);
	return 0;
}