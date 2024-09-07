#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<ll, ll> p[50020];
ll ymin[50020];
ll ymax[50020];
ll ans = 1e18;
void work()
{
	sort(p, p + n);
	ymin[n - 1] = p[n - 1].second;
	ymax[n - 1] = p[n - 1].second;
	for (int i = n - 2; i >= 0; i--)
	{
		ymin[i] = min(ymin[i + 1], p[i].second);
		ymax[i] = max(ymax[i + 1], p[i].second);
	}
	ll miny = p[0].second;
	ll maxy = p[0].second;
	for (int i = 0; i + 1 < n; i++)
	{
		miny = min(miny, p[i].second);
		maxy = max(maxy, p[i].second);
		ll t = (p[i].first - p[0].first) * (maxy - miny) + (p[n - 1].first - p[i + 1].first) * (ymax[i + 1] - ymin[i + 1]);
		ans = min(ans, t);
	}
}
int main()
{
	cin >> n;
	ll minx = 1e18;
	ll miny = 1e18;
	ll maxx = -1e18;
	ll maxy = -1e18;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
		minx = min(minx, p[i].first);
		maxx = max(maxx, p[i].first);
		miny = min(miny, p[i].second);
		maxy = max(maxy, p[i].second);
	}
	work();
	for (int i = 0; i < n; i++)
	{
		swap(p[i].first, p[i].second);
	}
	work();
	cout << (maxx - minx) * (maxy - miny) - ans << endl;
	return 0;
}