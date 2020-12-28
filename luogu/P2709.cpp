#include <bits/stdc++.h>
using namespace std;
const int b = 237;
int n, m;
int a[50020];
int c[50020];
int l[50020];
int r[50020];
int o[50020];
int x[50020];
int z;
void inc(int x)
{
	z += 2 * c[x]++ + 1;
}
void dec(int x)
{
	z -= 2 * --c[x] + 1;
}
bool cmp(int x, int y)
{
	if (l[x] / b == l[y] / b)
	{
		return r[x] < r[y];
	}
	else
	{
		return l[x] < l[y];
	}
}
int main()
{
	scanf("%d%d%*d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		o[i] = i;
	}
	sort(o, o + m, cmp);
	for (int i = 0, L = 2, R = 1; i < m; i++)
	{
		while (L > l[o[i]])
		{
			inc(a[--L]);
		}
		while (R < r[o[i]])
		{
			inc(a[++R]);
		}
		while (L < l[o[i]])
		{
			dec(a[L++]);
		}
		while (R > r[o[i]])
		{
			dec(a[R--]);
		}
		x[o[i]] = z;
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", x[i]);
	}
	return 0;
}