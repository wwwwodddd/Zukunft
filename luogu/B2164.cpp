#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[5002][5002];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
		}
	}
	printf("%d\n", c[n][m]);
	return 0;
}