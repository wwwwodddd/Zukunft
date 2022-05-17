#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int x, y, a, b;
int up = 1, dn = 1;
int pw(int x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main()
{
	cin >> x >> y;
	a = (2 * x - y) / 3;
	b = (2 * y - x) / 3;
	if ((x + y) % 3 != 0 || a < 0 || b < 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < b; i++)
	{
		up = (long long)up * (a + b - i) % p;
		dn = (long long)dn * (i + 1) % p;
	}
	cout << (long long)up * pw(dn, p - 2) % p << endl;
	return 0;
}
