#include <bits/stdc++.h>
using namespace std;
int n, m, a[10], c[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int f[10020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	f[0] = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = c[a[i]]; j <= n; j++)
		{
			f[j] = max(f[j], f[j - c[a[i]]] + 1);
		}
	}
	sort(a, a + m);
	for (int i = m - 1; i >= 0; i--)
	{
		while (n - c[a[i]] >= 0 && f[n] == f[n - c[a[i]]] + 1)
		{
			printf("%d", a[i]);
			n -= c[a[i]];
		}
	}
	printf("\n");
	return 0;
}