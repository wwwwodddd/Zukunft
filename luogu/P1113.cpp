#include <bits/stdc++.h>
using namespace std;
int n, l, x, z;
int f[10020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%*d%d", &l);
		while (scanf("%d", &x), x)
		{
			f[i] = max(f[i], f[x]);
		}
		f[i] += l;
		z = max(z, f[i]);
	}
	printf("%d\n", z);
	return 0;
}