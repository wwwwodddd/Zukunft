#include <bits/stdc++.h>
using namespace std;
int n, m, o, x, y;
int a[100020];
int c[100020];
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		z += c[a[i]]++;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &o, &x);
		if (o == 1)
		{
			scanf("%d", &y);
			z -= --c[a[x]];
			a[x] = y;
			z += c[a[x]]++;
		}
		else
		{
			z -= --c[a[x]];
			printf("%lld\n", z);
			z += c[a[x]]++;
		}
	}
	return 0;
}