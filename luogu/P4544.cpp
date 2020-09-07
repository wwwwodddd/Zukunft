#include <bits/stdc++.h>
using namespace std;
int n, m, l;
long long f[10020];
pair<int, pair<int, int> > a[520];
void gao(int x, long long y)
{
	for (int i = m; i >= x; i--)
	{
		f[i] = min(f[i], f[i - x] + y);
	}
}
int main()
{
	scanf("%d%d%d", &m, &l, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a[i].first, &a[i].second.first, &a[i].second.second);
	}
	sort(a, a + n);
	a[n].first = l;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= a[i].second.first; j *= 2)
		{
			a[i].second.first -= j;
			gao(j, (long long)j * a[i].second.second);
		}
		gao(a[i].second.first, (long long)a[i].second.first * a[i].second.second);
		for (int j = 0; j <= m; j++)
		{
			f[j] += (long long)j * j * (a[i + 1].first - a[i].first);
		}
	}
	printf("%lld\n", f[m]);
	return 0;
}