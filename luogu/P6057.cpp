#include <bits/stdc++.h>
using namespace std;
long long z;
int n, m, x, c[100020];
int main()
{
	scanf("%d%d", &n, &m);
	z = n * (n - 1LL) * (n - 2) / 3;
	for (int i = 0; i < 2 * m; i++)
	{
		scanf("%d", &x);
		c[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		z -= c[i] * (n - 1LL - c[i]);
	}
	printf("%lld\n", z / 2);
	return 0;
}