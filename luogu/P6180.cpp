#include <bits/stdc++.h>
using namespace std;
int s[100020][4];
int n, q, x, y;
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		memcpy(s[i], s[i-1], sizeof s[i]);
		scanf("%d", &x);
		s[i][x]++;
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		x--;
		printf("%d %d %d\n", s[y][1] - s[x][1], s[y][2] - s[x][2], s[y][3] - s[x][3]);
	}
	return 0;
}