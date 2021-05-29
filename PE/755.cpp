#include <bits/stdc++.h>
using namespace std;
const long long n = 10000000000000LL;
const int l = 100000000;
const int m = 36;
long long a[70] = {1, 2};
long long f[n + 1];
int main()
{
	for (int i = 2; i < 62; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	f[0] = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = l; j >= a[i]; j--)
		{
			f[j] += f[j - a[i]];
		}
	}
	for (int i = 1; i <= l; i++)
	{
		f[i] += f[i - 1];
	}
	long long z = 0;
	for (int i = 0; i < (1 << (62 - m)); i++)
	{
		long long t = n;
		for (int j = 0; j < (62 - m); j++)
		{
			if (i >> j & 1)
			{
				t -= a[m + j];
			}
		}
		if (0 <= t)
		{
			if (t <= l)
			{
				z += f[t];
			}
			else
			{
				z += f[l];
			}
		}
	}
	cout << z << endl;
	return 0;
}