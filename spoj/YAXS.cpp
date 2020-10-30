#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		int c[6] = {};
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			c[x]++;
		}
		int z = c[1] + min(c[2], c[3]) + min(c[4], c[5]);
		z = max(z, c[2] + min(c[3], c[1] + min(c[4], c[5])));
		z = max(z, c[3] + min(c[2], c[1] + min(c[4], c[5])));
		z = max(z, c[4] + min(c[5], c[1] + min(c[2], c[3])));
		z = max(z, c[5] + min(c[4], c[1] + min(c[2], c[3])));
		printf("Case %d: %d\n", tt, z);
	}
	return 0;
}