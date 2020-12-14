#include <bits/stdc++.h>
using namespace std;
int f[1020][1020];
int n, m, x, a, b, c;
int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		for (int j = m; j >= b; j--)
		{
			for (int k = x; k >= c; k--)
			{
				f[j][k] = max(f[j][k], f[j - b][k - c] + a);
			}
		}
	}
	printf("%d\n", f[m][x]);
	return 0;
}