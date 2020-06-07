#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcm(ll x, ll y)
{
	return x / __gcd(x, y) * y;
}
int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	cout << lcm(lcm(a, b), c) << endl;
	return 0;
}