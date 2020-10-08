#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;
ll F(ll x)
{
	if (x < 10)
	{
		return x;
	}
	ll y = x % 10, z = x / 10 + 8;
	while (x >= 10)
	{
		x /= 10;
	}
	return z + (x <= y);
}
int main()
{
	cin >> l >> r;
	cout << F(r) - F(l - 1) << endl;
	return 0;
}