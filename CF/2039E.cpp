#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int t, n = 1000000;
int f[1000020];
int g[1000020];
int s[1000020];
int r[1000020];
int main()
{
	for (long long i = 2; i <= n; i++)
	{
		if (i == 2)
		{
			g[i] = 0;
			s[i] = 0;
			r[i] = 0;
			f[i] = 1;
		}
		else
		{
			g[i] = (i - 3 + (i - 3) * (i - 2) / 2 + s[i - 1]) % p;
			s[i] = (s[i - 1] + g[i] * i) % p;
			r[i] = (r[i - 1] + g[i]) % p;
			f[i] = (g[i] + r[i - 1] + i - 1) % p;
		}
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}