#include <bits/stdc++.h>
using namespace std;
const int mod = 1234567891;
typedef long long ll;
vector<pair<int, int> >z;
int n;
int a[300];
vector<int> b, c;
int p[300];
int q[300];
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return (ll)a.first * b.second < (ll)b.first * a.second;
}
void fac(int x, vector<int> &a)
{
	for (int i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			a.push_back(i);
			if (i * i < x)
			{
				a.push_back(x / i);
			}
		}
	}
}
bool ok(int _p, int _q)
{
	p[0] = q[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p[i] = (ll)p[i-1] * _p % mod;
		q[i] = (ll)q[i-1] * _q % mod;
	}
	ll re = 0;
	for (int i = 0; i <= n; i++)
	{
		re = (re + (ll)a[i] * p[i] % mod * q[n - i]) % mod;
	}
	return !re;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int e = 0;
	while (a[e] == 0)
	{
		e++;
	}
	if(e > 0)
	{
		z.push_back(make_pair(0, 1));
	}
	fac(abs(a[e]), b);
	fac(abs(a[n]), c);
	for (int i: b)
	{
		for (int j: c)
		{
			if (__gcd(i, j) == 1)
			{
				if(ok(i, j))
				{
					z.push_back(make_pair(i, j));
				}
				if(ok(-i, j))
				{
					z.push_back(make_pair(-i, j));
				}
			}
		}
	}
	sort(z.begin(), z.end(), cmp);
	printf("%d\n", z.size());
	for (auto &i: z)
	{
		if (i.second == 1)
		{
			printf("%d\n", i.first);
		}
		else
		{
			printf("%d/%d\n", i.first, i.second);
		}
	}
	return 0;
}