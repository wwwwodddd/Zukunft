#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		a[n + 1] = 0;
		long long z = 0;
		for (int i = 1; i <= n; i++)
		{
			z += min(a[i], max(a[i - 1], a[i + 1]));
		}
		printf("%lld\n", z);
	}
	return 0;
}