#include <bits/stdc++.h>
using namespace std;
int n, l;
pair<int, int> a[1000020];
int b[1000020];
int c[1000020];
int d[1000020];
int p[1000020];
int t;
int q[1000020];
long long z, s;
void change(int *c, int x, int y)
{
	c[0]++;
	x++;
	for (int i = x; i <= n; i += i & -i)
	{
		c[i] += y;
	}
}
int query(int *c, int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += c[i];
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		b[i] = a[i].second;
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++)
	{
		p[i] = lower_bound(b, b + n, a[i].second) - b;
	}
	for (int i = 0; i < n; i++)
	{
		if (p[i] < i)
		{
			s += query(c, p[i]);
			s += *d - query(d, p[i]);
		}
		else
		{
			s += *d;
			s += *c - query(c, p[i]);
		}
		if (p[i] < i)
		{
			change(d, p[i], 1);
		}
		else
		{
			change(c, p[i], 1);
		}
	}
	z = s;
	for (int i = 0; i < n; i++)
	{
		if (p[i] < i)
		{
			t++;
			q[i - p[i]]++;
		}
		else
		{
			q[i - p[i] + n]++;
		}
	}
	long long c = 0;
	for (int i = 1; i < n; i++)
	{
		s += ((t + i - c) * 2LL - n - q[i]) * q[i];
		c += q[i];
		z = min(z, s);
	}
	printf("%lld\n", z);
	return 0;
}