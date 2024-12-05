#include <bits/stdc++.h>
using namespace std;
int n, m;
long long c[1000020];
int a[1000020];
void change(int x, int y)
{
	for (int i = x; i <= n; i += i & -i)
	{
		c[i] += y;
	}
}
long long query(int x)
{
	long long re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += c[i];
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int o, x, y, k;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d%d", &x, &y, &k);
			change(x, k);
			change(y + 1, -k);
		}
		else
		{
			scanf("%d", &x);
			printf("%lld\n", query(x) + a[x]);
		}
	}
	return 0;
}