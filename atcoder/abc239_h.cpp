#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, v;
map<int, int> f;
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
int F(int x)
{
	if (f.find(x) != f.end())
	{
		return f[x];
	}
	int s = 0;
	for (int i = 2; i <= n;)
	{
		int j;
		if (i > x)
		{
			j = n;
		}
		else
		{
			j = min(x / (x / i), n);
		}
		s = (s + (j - i + 1LL) * F(x / i)) % p;
		i = j + 1;
	}
	f[x] = (long long)(s + n) * v % p;
	return f[x];
}
int main()
{
	cin >> n >> m;
	v = pw(n - 1, p - 2);
	f[1] = 1;
	cout << F(m) << endl;
	return 0;
}