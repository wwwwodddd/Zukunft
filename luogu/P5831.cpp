#include <bits/stdc++.h>
using namespace std;
int b[30][30];
int a[30];
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[j]);
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < j; k++)
			{
				b[a[k]][a[j]]++;
			}
		}
	}
	int ans = 0;
	for (int j = 1; j <= n; j++)
	{
		for (int k = 1; k <= n; k++)
		{
			if (b[j][k] == m)
			{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}