#include <bits/stdc++.h>
using namespace std;
int n, m;
int w[1000020];
int v[1000020];
int l[1000020];
int r[1000020];
int c[1000020];
long long s[1000020];
long long t;
long long calc(int M)
{
	for (int i = 1; i <= n; i++)
	{
		c[i] = c[i - 1];
		s[i] = s[i - 1];
		if (w[i] >= M)
		{
			c[i]++;
			s[i] += v[i];
		}
	}
	long long t = 0;
	for (int i = 0; i < m; i++)
	{
		t += (c[r[i]] - c[l[i]]) * (s[r[i]] - s[l[i]]);
	}
	return t;
}
int main()
{
	scanf("%d%d%lld", &n, &m, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &w[i], &v[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		l[i]--;
	}
	int L = 0;
	int R = 1000001;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (calc(M) < t)
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	printf("%lld\n", min(abs(calc(L) - t), abs(calc(R) - t)));
	return 0;
}