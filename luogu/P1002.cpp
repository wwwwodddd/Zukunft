#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int dx[] = {1, 2, 1, -2, -1, 2, -1, -2, 0};
int dy[] = {2, 1, -2, 1, 2, -1, -2, -1, 0};
long long f[30][30];
bool v[30][30];
int main()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	x += 2;
	y += 2;
	for (int i = 0; i < 9; i++)
	{
		v[x + dx[i]][y + dy[i]] = true;
	}
	f[2][1] = 1;
	for (int i = 2; i <= n + 2; i++)
	{
		for (int j = 2; j <= m + 2; j++)
		{
			if (!v[i][j])
			{
				f[i][j] = f[i-1][j] + f[i][j-1];
			}
		}
	}
	printf("%lld\n", f[n+2][m+2]);
	return 0;
}