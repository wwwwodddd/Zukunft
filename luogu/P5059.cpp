#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p;
ll mul(ll x, ll y)
{
	ll re = 0;
	for (; y > 0; y >>= 3)
	{
		re = (re + y % 8 * x) % p;
		x = x * 8 % p;
	}
	return re;
}
void mul(ll a[2][2], ll b[2][2])
{
	ll w[2][2] = {};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				w[i][j] = (w[i][j] + mul(a[i][k], b[k][j])) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
ll F(ll n) {
	ll a[2][2] = {};
	ll b[2][2] = {};
	a[0][0] = a[1][1] = 1;
	b[0][0] = b[0][1] = b[1][0] = 1;
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
	return a[0][1];
}
ll pw(ll x, ll y)
{
	x = (x % p + p) % p;
	ll re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = mul(re, x);
		}
		x = mul(x, x);
	}
	return re;
}
int main()
{
	ll n;
	cin >> n >> p;
	n++;
	cout << pw(F(n + 2) - n - 1, n) << endl;
	return 0;
}