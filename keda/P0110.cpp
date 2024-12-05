#include <bits/stdc++.h>
using namespace std;
int a[1000020];
int n, m, x;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		int p = lower_bound(a, a + n, x) - a;
		if (p == n || a[p] != x)
		{
			p = -1;
		}
		else
		{
			p++;
		}
		printf("%d%c", p, i == m - 1 ? '\n' : ' ');
	}
	return 0;
}