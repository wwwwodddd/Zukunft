#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[300020];
bool ok(int x)
{
	long long z = 0;
	for (int i = 0; i < m; i++)
	{
		z += (a[i] + x - 1) / x;
	}
	return z <= n;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	int l = 0, r = 1e9;
	while (l < r - 1)
	{
		int o = (l + r) / 2;
		if (ok(o))
		{
			r = o;
		}
		else
		{
			l = o;
		}
	}
	printf("%d\n", r);
	return 0;
}
