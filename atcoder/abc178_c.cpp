#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n;
int pw(int x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % mod;
		}
		x = (long long)x * x % mod;
	}
	return re;
}
int main()
{
	cin >> n;
	cout << ((long long)pw(10, n) - 2 * pw(9, n) + pw(8, n) + 2 * mod) % mod << endl;
	return 0;
}
