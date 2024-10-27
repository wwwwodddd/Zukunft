#include <bits/stdc++.h>
using namespace std;
int n;
int xl[100020];
int xr[100020];
int yl[100020];
int yr[100020];
int yy[200020], yc;
long long ans;
pair<pair<int, int>, pair<int, int> > a[200020];
int v[1048577];
int s[1048577];
void change(int x, int l, int r, int L, int R, int w)
{
	if (L <= l && r <= R)
	{
		v[x] += w;
		if (v[x])
		{
			s[x] = yy[r] - yy[l];
		}
		else // if (l + 1 < r)
		{
			s[x] = s[x * 2] + s[x * 2 + 1];
		}
		return;
	}
	if (r <= L || R <= l)
	{
		return;
	}
	int m = (l + r) / 2;
	change(x * 2, l, m, L, R, w);
	change(x * 2 + 1, m, r, L, R, w);
	if (v[x])
	{
		s[x] = yy[r] - yy[l];
	}
	else
	{
		s[x] = s[x * 2] + s[x * 2 + 1];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &xl[i], &yl[i], &xr[i], &yr[i]);
		yy[yc++] = yl[i];
		yy[yc++] = yr[i];
	}
	sort(yy, yy + yc);
	yc = unique(yy, yy + yc) - yy;
	for (int i = 0; i < n; i++)
	{
		yl[i] = lower_bound(yy, yy + yc, yl[i]) - yy;
		yr[i] = lower_bound(yy, yy + yc, yr[i]) - yy;
		a[i + 0] = make_pair(make_pair(xl[i], +1), make_pair(yl[i], yr[i]));
		a[i + n] = make_pair(make_pair(xr[i], -1), make_pair(yl[i], yr[i]));
	}
	sort(a, a + 2 * n);
	for (int i = 0; i + 1 < 2 * n; i++)
	{
		change(1, 0, yc, a[i].second.first, a[i].second.second, a[i].first.second);
		ans += (long long)(a[i + 1].first.first - a[i].first.first) * s[1];
	}
	cout << ans << endl;
	return 0;
}