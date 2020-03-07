#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int sx[1000020];
int sy[1000020];
long long ans = 0;
map<int, vector<pair<int, int> > > xx, yy;
void gao(vector<pair<int, int> > &a, int s[])
{
	sort(a.begin(), a.end());
	long long s1 = 0, s2 = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s2 += a[i].first;
	}
	for (int i = 0; i < a.size(); i++)
	{
		s[a[i].second] = (i * a[i].first - s1) + (s2 - (a.size() - i) * a[i].first);
		s1 += a[i].first;
		s2 -= a[i].first;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		xx[x].push_back(make_pair(y, i));
		yy[y].push_back(make_pair(x, i));
	}
	for (auto &i: xx)
	{
		gao(i.second, sx);
	}
	for (auto &i: yy)
	{
		gao(i.second, sy);
	}
	for (int i = 0; i < n; i++)
	{
		ans = (ans + (long long)sx[i] * sy[i]) % mod;
	}
	printf("%d\n", (int)ans);
	return 0;
}