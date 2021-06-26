#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
typedef unsigned long long ull;
void read(ull &n, ull &m)
{
	char c;
	while (!isdigit(c = getchar()))
	{

	}
	n = c - '0';
	m = c - '0';
	while (isdigit(c = getchar()))
	{
		n = (n * 10 + c - '0') % ((p - 1LL) * p);
		m = (m * 10 + c - '0') % (p - 1);
	}
}
ull pw(ull x, ull y, ull p)
{
	ull re = 1;
	for (; y; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
ull S(ull r, ull n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n % 2 == 1)
	{
		return (S(r, n - 1) * r + 1) % p;
	}
	else
	{
		return S(r * r % p, n / 2) * (r + 1) % p;
	}
}
int main()
{
	ull n0, n1, m0, m1, a, b, c, d, e, f;
	read(n0, n1);
	read(m0, m1);
	cin >> a >> b >> c >> d;
	n0--;
	n1--;
	m0--;
	m1--;
	n0 += (p - 1LL) * p;
	n1 += p - 1;
	m0 += (p - 1LL) * p;
	m1 += p - 1;
	e = (c * pw(a, m1, p)) % p;
	f = (d * pw(a, m1, p) + b * S(a, m0)) % p;
	printf("%llu\n", ((pw(a, m1, p) + b * S(a, m0)) % p * pw(e, n1, p) % p + f * S(e, n0)) % p);
	return 0;
}