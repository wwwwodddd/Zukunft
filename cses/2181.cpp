#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int f[1025][1025];
int n, m;
bool ok(int x, int y)
{
	if (x & y)
	{
		return false;
	}
	int d = ((1 << m) - 1) ^ x ^ y;
	while (d > 0)
	{
		if (d % 2 == 0)
		{
			d /= 2;
		}
		else
		{
			if (d % 4 != 3)
			{
				return false;
			}
			d /= 4;
		}
	}
	return true;
}
int main()
{
	cin >> m >> n;
	f[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1 << m; j++)
		{
			if (f[i][j] == 0)
			{
				continue;
			}
			for (int k = 0; k < 1 << m; k++)
			{
				if (ok(j, k))
				{
					f[i + 1][k] = (f[i + 1][k] + f[i][j]) % p;
				}
			}
		}
	}
	cout << f[n][0] << endl;
	return 0;
}