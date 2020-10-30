#include <bits/stdc++.h>
int t, n, a[19] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		printf("Case %d: %d\n", tt, a[n]);
	}
	return 0;
}