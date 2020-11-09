#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll F(ll n)
{
	ll z = 0;
	for (ll t = 1; t < n; t *= 10)
	{
		z += n / 10 / t * t * 45;
		int d = n / t % 10;
		z += t * d * (d - 1) / 2;
		z += n % t * d;
	}
	return z;
}
ll n;
int main()
{
	cin >> n;
	cout << F(n + 1) << endl;
	return 0;
}