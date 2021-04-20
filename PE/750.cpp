#include <bits/stdc++.h>
using namespace std;
int n, a[999], p[999];
int f[999][999];
int main()
{
	n = 976;
	a[0] = 1;
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] * 3 % (n + 1);
		p[a[i]] = i;
		f[i][i] = 0;
	}
	for (int j = 1; j <= n; j++)
	{
		for (int i = j; i > 0; i--)
		{
			for (int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + abs(p[k] - p[j]));
			}
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}