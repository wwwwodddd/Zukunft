#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int c[100020];
int f[100020];
int n, l, x, y;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[i].first = x + y;
		a[i].second = x - y;
		f[i] = i;
	}
	sort(a, a + n);
	set<pair<int, int> > s;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (a[i].first - a[j].first > l)
		{
			s.erase(make_pair(a[j].second, j));
			j++;
		}
		set<pair<int, int> >::iterator it = s.lower_bound(make_pair(a[i].second, 0));
		if (it != s.end() && it->first - a[i].second <= l)
		{
			f[F(i)] = F(it->second);
		}
		if (it != s.begin())
		{
			it--;
			if (a[i].second - it->first <= l)
			{
				f[F(i)] = F(it->second);
			}
		}
		s.insert(make_pair(a[i].second, i));
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (F(i) == i)
		{
			ans1++;
		}
		ans2 = max(ans2, ++c[F(i)]);
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}