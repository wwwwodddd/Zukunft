#include <bits/stdc++.h>
using namespace std;
int n, m, L, R, a[5020], s[5020][5020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (i < j && a[i] > a[j]);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &L, &R);
		L--;
		printf("%d\n", s[R][R] - s[R][L] - s[L][R] + s[L][L]);
	}
	return 0;
}