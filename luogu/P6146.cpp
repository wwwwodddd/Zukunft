#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, x, y, z, c;
int a[200020];
int b[200020];
int main()
{
	scanf("%d", &n);
	for (int i = b[0] = 1; i <= n; i++)
	{
		b[i] = b[i - 1] * 2 % mod;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x] = +1;
		a[y] = -1;
	}
	for (int i = 1; i <= 2*n; i++)
	{
		c += a[i];
		if (a[i] == 1)
		{
			z = (z + b[n - c]) % mod;
		}
	}
	printf("%d\n", z);
	return 0;
}