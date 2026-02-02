#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 1000000007;
ll F(ll n)
{
	ll t = 1, z = 0;
	for (int i = 0; i < 19 && t < n; i++, t *= 10)
	{
		int d = n / t % 10;
		z = (z + n / 10 / t * t % p * 45) % p;
		z = (z + t % p * d * (d - 1) / 2) % p;
		z = (z + n % t % p * d) % p;
	}
	return z;
}
ll a, b;
int main()
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b;
		cout << (F(b + 1) + p - F(a)) % p << endl;
	}
	return 0;
}