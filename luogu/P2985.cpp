#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[50020];
int b[50020];
int c[50020];
bool ok(long long M)
{
	int d = 0;
	long long s = 0;
	for (int i = 0; i < n; i++)
	{
		b[i] = d + 1;
		s += a[i];
		while (s >= M)
		{
			s /= 2;
			d++;
		}
	}
	if (d >= m)
	{
		memcpy(c, b, sizeof c);
	}
	return d >= m;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	long long L = 0;
	long long R = 1e12;
	while (L < R - 1)
	{
		long long M = (L + R) / 2;
		if (ok(M))
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	printf("%lld\n", L);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", min(c[i], m));
	}
	return 0;
}