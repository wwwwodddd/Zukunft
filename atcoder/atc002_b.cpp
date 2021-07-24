#include <bits/stdc++.h>
using namespace std;
long long pw(long long x, long long y, long long mod)
{
	long long re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % mod;
		}
		x = x * x % mod;
	}
	return re;
}
long long n, m, p;
int main()
{
	cin >> n >> m >> p;
	cout << pw(n, p, m) << endl;
}