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
int y[50020];
int z;
void inc(int x)
{
	z += c[x]++;
}
void dec(int x)
{
	z -= --c[x];
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
	scanf("%d%d", &n, &m);
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
		if (l[o[i]] == r[o[i]])
		{
			x[o[i]] = 0;
			y[o[i]] = 1;
		}
		else
		{
			x[o[i]] = z;
			y[o[i]] = (r[o[i]] - l[o[i]] + 1LL) * (r[o[i]] - l[o[i]]) / 2;
			int g = __gcd(x[o[i]], y[o[i]]);
			x[o[i]] /= g;
			y[o[i]] /= g;
		}
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d/%d\n", x[i], y[i]);
	}
	return 0;
}