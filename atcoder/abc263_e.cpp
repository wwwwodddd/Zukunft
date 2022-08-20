#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n;
int a[200020];
int f[200020];
int s[200020];
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
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1; i > 0; i--)
	{
		f[i] = (s[i + 1] + p - s[i + 1 + a[i]]  + a[i] + 1LL) * pw(a[i], p - 2) % p;
		s[i] = (s[i + 1] + f[i]) % p;
	}
	cout << f[1] << endl;
	return 0;
}
