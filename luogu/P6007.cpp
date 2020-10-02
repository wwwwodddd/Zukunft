#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, int> a[200020];
int m, n;
int l[200020], lc;
long long f[200020];
long long c[200020];
long long query(int x)
{
	long long re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re = max(re, c[i]);
	}
	return re;
}
void change(int x, long long y)
{
	for (int i = x; i <= lc; i += i & -i)
	{
		c[i] = max(c[i], y);
	}
}
int Q(int y)
{
	return lower_bound(l, l + lc, y) - l + 1;
}
int main()
{
	scanf("%d%d", &m, &n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first.first, &a[i].first.second);
		a[i].second = i + 1;
		l[lc++] = a[i].first.second;
		scanf("%d%d", &a[i + n].first.first, &a[i + n].first.second);
		a[i + n].second = -i - 1;
		l[lc++] = a[i + n].first.second;
	}
	sort(a, a + 2 * n);
	sort(l, l + lc);
	lc = unique(l, l + lc) - l;
	for (int i = 0; i < 2 * n; i++)
	{
		if (a[i].second > 0)
		{
			f[a[i].second] = query(Q(a[i].first.second));
			f[a[i].second] -= a[i].first.first + a[i].first.second;
		}
		else
		{
			f[-a[i].second] += a[i].first.first + a[i].first.second;
			change(Q(a[i].first.second), f[-a[i].second]);
			ans = max(ans, f[-a[i].second]);
		}
	}
	printf("%lld\n", 2 * m - ans);
	return 0;
}