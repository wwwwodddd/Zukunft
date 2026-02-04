#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
int a[1 << 24];
int b[2];
int f[1 << 24];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[1 << i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	f[0] = 1;
	for (int i = 1; i < 1 << n; i++)
	{
		a[i] = a[i & -i] + a[i & (i - 1)];
		if (a[i] == b[0] || a[i] == b[1])
		{
			continue;
		}
		for (int j = i; j > 0; j -= j & -j)
		{
			f[i] = (f[i] + f[i ^ (j & -j)]) % p;
		}
	}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}