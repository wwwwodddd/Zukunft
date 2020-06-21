#include <bits/stdc++.h>
using namespace std;
int l, n, m;
int a[100020];
bool ok(int t)
{
	int re = 0;
	for (int i = 0; i <= n; i++)
	{
		if (a[i] - a[i-1] > t)
		{
			re += (a[i] - a[i-1] - 1) / t;
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
	int R = l;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	printf("%d\n", R);
	return 0;
}