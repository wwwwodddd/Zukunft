#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, s, z = 1e9;
int h[2][30020];
int *f = h[0], *g = h[1];
int main()
{
	memset(f, 0x3f, sizeof h[0]);
	f[0] = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		s += max(a, c);
		swap(f, g);
		for (int j = 0; j <= s + 5; j++)
		{
			f[j] = 1e9;
		}
		for (int j = 0; j <= s; j++)
		{
			if (a > 0 && j >= a)
			{
				f[j] = min(f[j], g[j - a]);
			}
			if (b > 0)
			{
				f[j] = min(f[j], g[j] + b);
			}
			if (c > 0 && j >= c)
			{
				f[j] = min(f[j], g[j - c] + c);
			}
		}
	}
	for (int i = 0; i <= s; i++)
	{
		z = min(z, max(i, f[i]));
	}
	cout << z << endl;
	return 0;
}