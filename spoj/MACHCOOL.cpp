#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[100];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int z = 86400;
		for (int i = m; i < n; i++)
		{
			z = min(z, a[i] - a[i - m]);
		}
		printf("%d\n", z);
	}
	return 0;
}