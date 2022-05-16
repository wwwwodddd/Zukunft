#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t;
long long n, x;
struct INT
{
	int x, y;
	INT(long long _x, long long _y = 0) : x(_x % p), y(_y % p)
	{
		if (x < 0)
		{
			x += p;
		}
		if (y < 0)
		{
			y += p;
		}
	}
	void print() const
	{
		printf("%d %d\n", x, y);
	}
};
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
INT operator+(const INT &a, const INT &b)
{
	return INT((a.x + b.x) % p, (a.y + b.y) % p);
}
INT operator-(const INT &a, const INT &b)
{
	return INT((a.x + p - b.x) % p, (a.y + p - b.y) % p);
}
INT operator*(const INT &a, const INT &b)
{
	return INT((1LL * a.x * b.x + 5LL * a.y * b.y) % p, (1LL * a.x * b.y + 1LL * a.y * b.x) % p);
}
INT inv(const INT &a)
{
	int r = (1LL * a.x * a.x + p - 5LL * a.y * a.y % p) % p;
	return INT(a.x, -a.y) * pw(r, p - 2);
}
INT operator/(const INT &a, const INT &b)
{
	return a * inv(b);
}
INT pw(INT x, long long y)
{
	INT re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x;
		}
		x = x * x;
	}
	return re;
}
INT S(INT r, long long n)
{
	return (pw(r, n) - 1) / (r - 1);
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> x;
		INT r1 = INT(1, 1) / 2 * x;
		INT r2 = INT(1, -1) / 2 * x;
		n++;
		INT re = (S(r1, n) - S(r2, n));
		cout << re.y << endl;
	}
	return 0;
}