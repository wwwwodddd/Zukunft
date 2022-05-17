#include <bits/stdc++.h>
using namespace std;
int n, a[20], b[20];
long long x, y;
long long f[262145];
int main()
{
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < 1 << n; i++)
	{
		int c = __builtin_popcount(i), d = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			if (i >> j & 1)
			{
				d++;
			}
			else
			{
				f[i | 1 << j] = min(f[i | 1 << j], f[i] + d * y + abs(a[j] - b[c]) * x);
			}
		}
	}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}
