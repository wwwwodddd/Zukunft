#include <bits/stdc++.h>
using namespace std;
int f[250000], n, m;
const int p = 1000000007;
int main()
{
	cin >> n;
	m = n * (n + 1) / 2;
	if (m & 1)
	{
		cout << 0 << endl;
	}
	else
	{
		f[0] = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = m / 2; j >= i; j--)
			{
				f[j] = (f[j] + f[j - i]) % p;
			}
		}
		cout << f[m / 2] << endl;
	}
	return 0;
}