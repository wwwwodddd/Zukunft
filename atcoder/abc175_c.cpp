#include <bits/stdc++.h>
using namespace std;
long long x, k, d;
int main()
{
	cin >> x >> k >> d;
	x = abs(x);
	if (x / d > k)
	{
		x -= k * d;
	}
	else
	{
		k -= x / d;
		x %= d;
		if (k & 1)
		{
			x = d - x;
		}
	}
	cout << x << endl;
	return 0;
}
