#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, x, s;
long long f[90020], g[90020], z = 1;
int main()
{
	cin >> n;
	f[0] = 1;
	g[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		z = z * 3 % p;
		cin >> x;
		s += x;
		for (int i = s; i >= x; i--)
		{
			f[i] = (f[i] + f[i - x] * 2) % p;
			g[i] = (g[i] + g[i - x]) % p;
		}
	}
	for (int i = 0; 2 * i <= s; i++)
	{
		z = (z - 3 * f[i]) % p;
	}
	if (s % 2 == 0)
	{
		z = (z + 3 * g[s / 2]) % p;
	}
	if (z < 0)
	{
		z += p;
	}
	cout << z << endl;
	return 0;
}