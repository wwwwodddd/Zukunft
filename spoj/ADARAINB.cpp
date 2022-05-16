#include <bits/stdc++.h>
using namespace std;
int n, m, l, xa, ya, xb, yb;
int s[5020][5020];
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		xb++;
		yb++;
		s[xa][ya]++;
		s[xa][yb]--;
		s[xb][ya]--;
		s[xb][yb]++;
	}
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &xa, &ya);
		printf("%d\n", s[xa][ya]);
	}
	return 0;
}