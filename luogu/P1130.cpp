#include <bits/stdc++.h>
using namespace std;
int n, m, a[2020][2020];
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int j = 1; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			a[i][j] += min(a[i][j - 1], a[(i + n - 1) % n][j - 1]);
		}
	}
	int z = a[0][m - 1];
	for (int i = 0; i < n; i++)
	{
		z = min(z, a[i][m - 1]);
	}
	printf("%d\n", z);
	return 0;
}