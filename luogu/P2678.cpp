#include <bits/stdc++.h>
using namespace std;
int l, n, m;
int a[50020];
bool ok(int t)
{
	int re = 0, s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - a[s] >= t)
		{
			s = i;
		}
		else
		{
			re++;
		}
	}
	return re <= m;
}
int main()
{
	scanf("%d%d%d", &l, &n, &m);
	a[0] = 0;
	a[n + 1] = l;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int L = 0;
	int R = l + 1;
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
	printf("%d\n", L);
	return 0;
}