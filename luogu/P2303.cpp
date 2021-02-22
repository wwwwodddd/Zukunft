#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, z;

void fac(ll n, vector<pair<ll, ll> > &a)
{
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ll cnt = 0;
			while (n % i == 0)
			{
				n /= i;
				cnt++;
			}
			a.push_back(make_pair(i, cnt));
		}
	}
	if (n > 1)
	{
		a.push_back(make_pair(n, 1));
	}
}

void gen(const vector<pair<ll, ll> > &b, vector<pair<ll, ll> > &a, int d, ll x, ll y)
{
	if (d == b.size())
	{
		a.push_back(make_pair(x, y));
		return;
	}
	for (int i = 0; i <= b[d].second; i++)
	{
		gen(b, a, d + 1, x, y);
		x *= b[d].first;
		if (i == 0)
		{
			y *= b[d].first - 1;
		}
		else
		{
			y *= b[d].first;
		}
	}
}

int main()
{
	scanf("%lld", &n);
	vector<pair<ll, ll> > a, b;
	fac(n, b);
	gen(b, a, 0, 1, 1);
	for (int i = 0; i < a.size(); i++)
	{
		z += n / a[i].first * a[i].second;
	}
	printf("%lld\n", z);
	return 0;
}