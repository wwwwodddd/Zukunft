#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int s[1020][1020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &s[i + j - 1][i + n - j]);
		}
	}
	for (int i = 1; i < 2 * n; i++)
	{
		for (int j = 1; j < 2 * n; j++)
		{
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int xa = max(0, i + j - 1 - m - 1), xb = min(2 * n - 1, i + j - 1 + m);
			int ya = max(0, i + n - j - m - 1), yb = min(2 * n - 1, i + n - j + m);
			z = max(z, s[xb][yb] - s[xb][ya] - s[xa][yb] + s[xa][ya]);
		}
	}
	printf("%d\n", z);
	return 0;
}