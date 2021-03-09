#include <bits/stdc++.h>
using namespace std;
int n;
int a[320];
int f[320][320];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n; i > 0; i--)
	{
		f[i][i] = 1;
		for (int j = i + 1; j <= n; j++)
		{
			f[i][j] = f[i][j-1] + (a[i] != a[j]);
			for (int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
			}
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}