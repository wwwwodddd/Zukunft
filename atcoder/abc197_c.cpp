#include <bits/stdc++.h>
using namespace std;
int n, a[20];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int z = 1 << 30;
	for (int i = 0; i < 1 << n - 1; i++)
	{
		int x = 0, o = 0;
		for (int j = 0; j < n; j++)
		{
			o |= a[j];
			if (~i >> j & 1)
			{
				x ^= o;
				o = 0;
			}
		}
		z = min(z, x);
	}
	cout << z << endl;
	return 0;
}
