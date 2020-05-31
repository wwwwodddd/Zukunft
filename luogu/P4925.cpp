#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, l, p, s, w, z;
ll pw(ll x, ll y)
{
	ll re = 1;
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
int main()
{
	cin >> k >> l >> p >> s >> w;
	k %= p;
	z = 1;
	if (l >= 2)
	{
		z = (k+p-1) * pw(k+p-2, l-2) % p;
	}
	if (!s)
	{
		z = z * k % p;
	}
	cout << z << endl;
	return 0;
}