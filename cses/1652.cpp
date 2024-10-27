#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[1020];
int s[1020][1020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", c + 1);
		for (int j = 1; j <= n; j++)
		{
			s[i][j] = (c[j] == '*');
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int xa, ya, xb, yb;
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		xa--;
		ya--;
		printf("%d\n", s[xb][yb] - s[xb][ya] - s[xa][yb] + s[xa][ya]);
	}
	return 0;
}