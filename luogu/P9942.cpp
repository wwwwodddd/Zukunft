#include <bits/stdc++.h>
using namespace std;
int n;
int a[22];
int b[22];
long long f[1 << 22];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	f[0] = 1;
	for (int i = 0; i < 1 << n; i++)
	{
		int k = __builtin_popcount(i);
		for (int j = 0; j < n; j++)
		{
			if (~i >> j & 1)
			{
				if (a[j] <= b[k])
				{
					f[i | 1 << j] += f[i];
				}
			}
		}
	}
	printf("%lld\n", f[(1 << n) - 1]);
	return 0;
}