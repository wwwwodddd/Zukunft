#include <bits/stdc++.h>
using namespace std;
int n, m;
int r[1000020];
int d[1000020];
int s[1000020];
int t[1000020];
long long c[1000020];
bool ok(int M)
{
	memset(c, 0, sizeof c);
	for (int i = 0; i < M; i++)
	{
		c[s[i]] += d[i];
		c[t[i]] -= d[i];
	}
	for (int i = 1; i <= n; i++)
	{
		c[i] += c[i - 1];
		if (r[i] < c[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &r[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &d[i], &s[i], &t[i]);
		t[i]++;
	}
	int L = 0;
	int R = m + 1;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	if (L == m)
	{
		printf("0\n");
	}
	else
	{
		printf("-1\n%d\n", R);
	}
	return 0;
}