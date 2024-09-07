#include <bits/stdc++.h>
using namespace std;
int n, q, k;
int a[300020];
int f[300020];
int z[300020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= i)
		{
			f[i] = max(f[i], f[i - a[i]] + 1);
			z[f[i] + n - i] = max(z[f[i] + n - i], i);
		}
		else
		{
			z[n - a[i] + 1] = max(z[n - a[i] + 1], i);
		}
		f[i] = max(f[i], f[i - 1]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		z[i] = max(z[i], z[i + 1]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &k);
		printf("%d\n", z[k]);
	}
	return 0;
}