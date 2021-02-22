#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
typedef long long ll;
int t, n;
ll pw(ll x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}

void fac(int n, vector<pair<int, int> > &a)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			int cnt = 0;
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

void gen(const vector<pair<int, int> > &b, vector<pair<int, int> > &a, int d, int x, int y)
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
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		vector<pair<int, int> > a, b;
		fac(n, b);
		gen(b, a, 0, 1, 1);
		ll z = 0;
		for (int i = 0; i < a.size(); i++)
		{
			z = (z + pw(n, n / a[i].first) * a[i].second) % p;
		}
		z = z * pw(n, p - 2) % p;
		printf("%lld\n", z);
	}
	return 0;
}