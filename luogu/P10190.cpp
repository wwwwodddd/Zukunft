#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace cao
{
	int t, n;
	ll x1;
	ll y1[200020];
	ll y2[200020];
	ll x2[200020];
	ll s[200020];
	vector<ll> yy;
	vector<ll> pos;
	vector<ll> neg;
	vector<pair<ll, ll> > up;
	vector<pair<ll, ll> > dn;
	ll yc;
	double xm(double x1, double y1, double x2, double y2)
	{
		return x1 * y2 - x2 * y1;
	}
	bool cmpmax(pair<ll, ll> a, pair<ll, ll> b)
	{
		return xm(a.first, a.second - yc, b.first, b.second - yc) > 0;
	}
	bool cmpmin(pair<ll, ll> a, pair<ll, ll> b)
	{
		return xm(a.first, a.second - yc, b.first, b.second - yc) > 0;
	}
	bool checkmax(ll y) // neg up
	{
		yc = y;
		sort(up.begin(), up.end(), cmpmax);
		for (int i = 0; i < up.size(); i++)
		{
			if (up[i].second - up[i].first * neg[i] > y)
			{
				return false;
			}
		}
		return true;
	}
	bool checkmin(ll y) // pos dn
	{
		yc = y;
		sort(dn.begin(), dn.end(), cmpmin);
		for (int i = 0; i < dn.size(); i++)
		{
			if (dn[i].second - dn[i].first * pos[i] < y)
			{
				return false;
			}
		}
		return true;
	}
	void gan()
	{
		yy.clear();
		pos.clear();
		neg.clear();
		up.clear();
		dn.clear();
		cin >> n >> x1;
		for (int i = 0; i < n; i++)
		{
			cin >> y1[i] >> y2[i] >> x2[i];
			yy.push_back(y1[i]);
			yy.push_back(y2[i]);
			up.push_back(make_pair(x2[i], y2[i]));
			dn.push_back(make_pair(x2[i], y1[i]));
		}
		for (int i = 0; i < 4 * n; i++)
		{
			cin >> s[i];
			if (s[i] > 0)
			{
				pos.push_back(s[i]);
			}
			else
			{
				neg.push_back(s[i]);
			}
		}
		if (pos.size() < n || neg.size() < n)
		{
			cout << -1 << endl;
			return;
		}
		sort(yy.begin(), yy.end());
		assert(yy.size() + n + n == pos.size() + neg.size());
		for (int i = 0; i < pos.size() - n; i++)
		{
			dn.push_back(make_pair(x1, yy[yy.size() - 1 - i]));
		}
		for (int i = 0; i < neg.size() - n; i++)
		{
			up.push_back(make_pair(x1, yy[i]));
		}
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());
		ll maxyl = -4e18;
		ll maxyr = 4e18;
		while (maxyl < maxyr - 1)
		{
			ll maxym = (maxyl + maxyr) / 2;
			if (checkmax(maxym))
			{
				maxyr = maxym;
			}
			else
			{
				maxyl = maxym;
			}
		}
		ll minyl = -4e18;
		ll minyr = 4e18;
		while (minyl < minyr - 1)
		{
			ll minym = (minyl + minyr) / 2;
			if (checkmin(minym))
			{
				minyl = minym;
			}
			else
			{
				minyr = minym;
			}
		}
		// cout << maxyr << " " << minyl << endl;
		cout << maxyr - minyl << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cao::gan();
	}
	return 0;
}