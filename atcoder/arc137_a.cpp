#include <bits/stdc++.h>
using namespace std;
long long l, r;
int main()
{
	cin >> l >> r;
	for (long long d = r - l; d > 0; d--)
	{
		for (long long x = l; x + d <= r; x++)
		{
			long long y = x + d;
			if (__gcd(x, y) == 1)
			{
				cout << d << endl;
				return 0;
			}
		}
	}
}
