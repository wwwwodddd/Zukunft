#include <bits/stdc++.h>
using namespace std;
int n, a[2020];
int f[2020][2020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i; j <= n; j++)
		{
			f[i][j] = max(f[i][j - 1] + a[j] * (n - j + i), f[i + 1][j] + a[i] * (n - j + i));
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}