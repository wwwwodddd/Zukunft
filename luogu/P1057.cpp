#include <bits/stdc++.h>
using namespace std;
int n, m, f[32][32];
int main()
{
	scanf("%d%d", &n, &m);
	f[0][0] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f[i][j] = f[i - 1][(j + n - 2) % n] + f[i - 1][j];
		}
	}
	printf("%d\n", f[m][m % n]);
	return 0;
}