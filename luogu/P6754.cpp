#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll F(ll n)
{
	ll t = 1, z = (n > 0), x = 1;
	int lc = 0, rc = 0;
	while (t * 10 <= n)
	{
		if (rc < 2)
		{
			x *= 9;
		}
		else
		{
			x *= 8;
		}
		z += x;
		t *= 10;
		rc++;
	}
	while (t > 0)
	{
		int d = n / t % 10;
		for (int i = (lc == 0); i < d; i++)
		{
			if ((lc >= 1 && i == n / 10 / t % 10) || (lc >= 2 && i == n / 100 / t % 10))
			{
				continue;
			}
			if (lc == 0 && rc > 0)
			{
				z += 9LL << (3 * (rc - 1));
			}
			else
			{
				z += 1LL << (3 * rc);
			}
		}
		if ((lc >= 1 && d == n / 10 / t % 10) || (lc >= 2 && d == n / 100 / t % 10))
		{
			break;
		}
		t /= 10;
		rc--;
		lc++;
	}
	return z;
}
int main()
{
	ll a, b;
	cin >> a >> b;
	cout << F(b + 1) - F(a) << endl;
	return 0;
}