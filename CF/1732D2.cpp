#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
char o;
ll x;
set<ll> s;
map<ll, ll> z;
map<ll, set<ll> > v;
map<ll, set<ll> > d;
int main()
{
	s.insert(0);
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> o >> x;
		if (o == '+')
		{
			for (ll j : v[x])
			{
				d[j].erase(x);
			}
			s.insert(x);
		}
		else if (o == '?')
		{
			ll &r = z[x];
			while (s.count(r))
			{
				v[r].insert(x);
				r += x;
			}
			if (d[x].size())
			{
				cout << *d[x].begin() << endl;
			}
			else
			{
				cout << r << endl;
			}
		}
		else
		{
			for (ll j : v[x])
			{
				d[j].insert(x);
			}
			s.erase(x);
		}
	}
	return 0;
}