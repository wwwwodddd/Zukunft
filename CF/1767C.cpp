#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n;
int a[120][120];
int f[120];
bool ok(int l, int r)
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (i <= l - 1 && l <= j)
			{
				if (a[i][j] == 1)
				{
					return false;
				}
			}
			if (l <= i && j <= r)
			{
				if (a[i][j] == 2)
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	f[0] = 2;
	for (int j = 0; j < n; j++)
	{
		for (int i = j + 1; i <= n; i++)
		{
			if (ok(j + 1, i))
			{
				f[i] = (f[i] + f[j]) % p;
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}