#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n = 1000000;
int f[1000020];
int g[1000020];
int main()
{
	f[1] = 1;
	g[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] = (f[i - 1] * 4LL + g[i - 1]) % p;
		g[i] = (g[i - 1] * 2LL + f[i - 1]) % p;
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << (f[n] + g[n]) % p << endl;
	}
	return 0;
}