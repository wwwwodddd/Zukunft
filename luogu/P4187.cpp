#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, k;
long long f[1000020], ans;
int main()
{
	cin >> n >> m >> k;
	f[0] = 1;
	ans = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * m % p;
		if (i == k)
		{
			f[i] -= m;
		}
		else if (i > k)
		{
			f[i] = (f[i] - f[i - k] * (m - 1) % p + p) % p;
		}
		ans = ans * m % p;
	}
	cout << (ans + p - f[n]) % p << endl;
}