#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int f[250020];
int n, k;
int main()
{
	f[0] = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i * (i - 1) / 2; j++)
		{
			f[j] = (f[j] + f[j - 1]) % p;
		}
		for (int j = i * (i - 1) / 2; j >= i; j--)
		{
			f[j] = (f[j] + p - f[j - i]) % p;
		}
	}
	cout << f[k] << endl;
	return 0;
}