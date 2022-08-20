#include <bits/stdc++.h>
using namespace std;
int t;
long long x, y, z, u, v, g;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> x >> z; // z = x * y * gcd(x, y)
		if (z % x != 0)
		{
			cout << -1 << endl;
			continue;
		}
		u = z / x; // u = y * gcd(x, y)
		v = __gcd(x * x, u); // v = gcd(x * x, y * gcd(x, y)) = gcd(x, y) ** 2
		g = int(sqrt(v)); // g = gcd(x, y)
		if (g * g != v)
		{
			cout << -1 << endl;
			continue;
		}
		y = u / g;
		cout << y << endl;
	}
	return 0;
}
