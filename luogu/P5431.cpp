#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b=2) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
}FM;
ull n, p, k;
ull read()
{
	ull n = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar())
	{
	}
	for (; isdigit(c); c = getchar())
	{
		n = n * 10 + c - '0';
	}
	return n;
}
ull pw(ull x, int y)
{
	ull re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = FM.reduce(re * x);
		}
		x = FM.reduce(x * x);
	}
	return re;
}
ull a[5000020];
ull b[5000020];
ull z, t = 1;
int main()
{
	n = read();
	p = read();
	k = read();
	FM = FastMod(p);
	b[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		b[i] = FM.reduce(b[i - 1] * a[i]);
	}
	b[n] = pw(b[n], p - 2);
	for (int i = n; i > 0; i--)
	{
		b[i - 1] = FM.reduce(b[i] * a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		t = FM.reduce(t * k);
		z = FM.reduce(z + t * b[i]);
		t = FM.reduce(t * a[i]);
	}
	cout << z << endl;
	return 0;
}