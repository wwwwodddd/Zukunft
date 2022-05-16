#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int t, n, s, l;
long long m;
long long a[800020];
long long b[800020];
struct BIT
{
	vector<int> c;
	int n;
	void init(int l)
	{
		n = l;
		c.clear();
		c.resize(n + 1);
	}
	void change(int x, int y)
	{
		assert(1 <= x && x <= n);
		for (int i = x; i <= n; i += i & -i)
		{
			c[i] += y;
			if (c[i] >= mod)
			{
				c[i] -= mod;
			}
		}
	}
	int query(int x)
	{
		assert(0 <= x && x <= n);
		int re = 0;
		for (int i = x; i > 0; i -= i & -i)
		{
			re += c[i];
			if (re >= mod)
			{
				re -= mod;
			}
		}
		return re;
	}
}f[20];
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%lld%d", &n, &m, &s);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			b[i] = a[i];
		}
		sort(b, b + n);
		l = unique(b, b + n) - b;
		for (int i = 0; i < s; i++)
		{
			f[i].init(l);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			int x = lower_bound(b, b + l, a[i]) - b + 1;
			int p = lower_bound(b, b + l, a[i] - m) - b;
			for (int j = 0; j < s; j++)
			{
				int y = j > 0 ? f[j - 1].query(p) : 1;
				f[j].change(x, y);
			}
		}
		printf("Case %d: %d\n", tt, f[s - 1].query(l));
	}
	return 0;
}