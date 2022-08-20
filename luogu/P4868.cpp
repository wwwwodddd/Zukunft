#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100020]; 
long long c0[100020];
long long c1[100020];
void change(long long c[], int x, long long y)
{
	for (int i = x; i <= n; i += i & -i)
	{
		c[i] += y;
	}
}
long long query(long long c[], int x)
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
		scanf("%lld", &a[i]);
		change(c0, i, a[i]);
		change(c1, i, a[i] * i);
	}
	for (int i = 0; i < m; i++)
	{
		char o[7];
		int x, y;
		scanf("%s", o);
		if (*o == 'Q')
		{
			scanf("%d", &x);
			printf("%lld\n", (x + 1) * query(c0, x) - query(c1, x));
		}
		else
		{
			scanf("%d%d", &x, &y);
			change(c0, x, y - a[x]);
			change(c1, x, (y - a[x]) * x);
			a[x] = y;
		}
	}
	return 0;
}
