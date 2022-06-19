#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, x;
int f[3020];
int main()
{
	cin >> n >> m;
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		for (int j = m; j >= 0; j--)
		{
			f[j] = f[j] * 2 % p;
			if (j >= x)
			{
				f[j] = (f[j] + f[j - x]) % p;
			}
		}
	}
	cout << f[m] << endl;
	return 0;
}