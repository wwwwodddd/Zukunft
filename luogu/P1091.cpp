#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[120];
int f[120];
int g[120];
int main()
{
	scanf("%d", &n);
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		int p = lower_bound(f, f + n, a[i]) - f;
		g[i] = p + 1;
		f[p] = a[i];
	}
	memset(f, 0x3f, sizeof f);
	for (int i = n - 1; i >= 0; i--)
	{
		int p = lower_bound(f, f + n, a[i]) - f;
		f[p] = a[i];
		z = max(z, g[i] + p);
	}
	printf("%d\n", n - z);
	return 0;
}