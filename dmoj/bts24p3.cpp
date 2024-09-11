#include <bits/stdc++.h>
using namespace std;
int n;
int a[524289];
int b[524289];
int c[524289];
long long f[524289];
long long g[524289];
long long z[524289];
long long sqr(long long x)
{
	return x * x;
}
void gao(int p)
{
	if (p < n)
	{
		z[p * 2] = sqr(c[p * 2] - a[p * 2 + 1]) + f[p * 2 + 1];
		z[p * 2 + 1] = sqr(b[p * 2] - c[p * 2 + 1]) + g[p * 2];
		gao(p * 2);
		gao(p * 2 + 1);
	}
}
int main()
{
	scanf("%d", &n);
	int s = n;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a[n + i]);
		s ^= a[n + i];
		b[n + i - 1] = a[n + i];
	}
	a[n] = b[n + n - 1] = s;
	for (int i = 0; i < n; i++)
	{
		c[n + i] = s;
	}
	for (int i = n - 1; i > 0; i--)
	{
		a[i] = max(a[i * 2], a[i * 2 + 1]);
		f[i] = f[i * 2] + f[i * 2 + 1] + sqr(a[i * 2] - a[i * 2 + 1]);
		b[i] = max(b[i * 2], b[i * 2 + 1]);
		g[i] = g[i * 2] + g[i * 2 + 1] + sqr(b[i * 2] - b[i * 2 + 1]);
		assert(max(c[i * 2], a[i * 2 + 1]) == max(c[i * 2 + 1], b[i * 2]));
		c[i] = max(c[i * 2 + 1], b[i * 2]);
	}
	gao(1);
	for (int i = 1; i < 2 * n; i++)
	{
		z[i] += z[i / 2];
	}
	for (int i = n; i < 2 * n; i++)
	{
		printf("%lld%c", z[i], i == 2 * n - 1 ? '\n' : ' ');
	}
	return 0;
}