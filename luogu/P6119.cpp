#include <bits/stdc++.h>
using namespace std;
int n;
int a[1020];
int b[1020];
int f[1020][1020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (abs(a[i] - b[j]) <= 4)
			{
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	printf("%d\n", f[n][n]);
	return 0;
}