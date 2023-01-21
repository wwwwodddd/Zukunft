#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, p;
long long f[200020] = {0, 1};
int main()
{
	cin >> n >> p;
	for (int i = 2; i <= n; i++)
	{
		f[i] = ((p * f[i - 2] + (100 - p) * f[i - 1]) % mod * 828542813 + 1) % mod;
	}
	cout << f[n] << endl;
	return 0;
}
