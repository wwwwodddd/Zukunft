#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int p[100020];
int c[100020];
void R(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int G(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			p[x] = i;
			c[i] = 0;
		}
		long long z = 0;
		for (int i = n; i > 0; i--)
		{
			z += G(p[i]);
			R(p[i], 1);
		}
		printf("%lld\n", z);
	}
	return 0;
}