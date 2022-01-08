#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long a = 1, b, c, d;
int main()
{
	int h, w, k, x1, y1, x2, y2;
	cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < k; i++)
	{
		long long na, nb, nc, nd;
		na = (b * (w-1) + c * (h-1)) % p;
		nb = (b * (w-2) + a + d * (h-1)) % p;
		nc = (c * (h-2) + a + d * (w-1)) % p;
		nd = (d * (h+w-4) + c + b) % p;
		a = na;
		b = nb;
		c = nc;
		d = nd;
	}
	if (x1 == x2 && y1 == y2)
	{
		cout << a << endl;
	}
	else if (x1 == x2)
	{
		cout << b << endl;
	}
	else if (y1 == y2)
	{
		cout << c << endl;
	}
	else
	{
		cout << d << endl;
	}
	return 0;
}

