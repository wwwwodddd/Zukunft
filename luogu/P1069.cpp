#include <bits/stdc++.h>
using namespace std;
int n, m, l, c, x;
int a[9];
int b[9];
int gao(int x)
{
	int  z = 0;
	for (int i = 0; i < c; i++)
	{
		int t = 0;
		for (; x % a[i] == 0; x /= a[i])
		{
			t++;
		}
		if (t == 0)
		{
			return 1e9;
		}
		z = max(z, (b[i] + t - 1) / t);
	}
	return z;
}
int main()
{
	cin >> n >> m >> l;
	for (int i = 2; i <= m; i++)
	{
		if (m % i == 0)
		{
			a[c] = i;
			for (; m % i == 0; m /= i)
			{
				b[c]++;
			}
			b[c] *= l;
			c++;
		}
	}
	int z = 1e9;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		z = min(z, gao(x));
	}
	if (z == 1e9)
	{
		z = -1;
	}
	cout << z << endl;
	return 0;
}