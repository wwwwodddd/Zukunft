#include <bits/stdc++.h>
using namespace std;
int n, x, z = -999;
int b[150][150];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			b[i][j] = b[i - 1][j] + x;
		}
	}
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = i1 + 1; i2 <= n; i2++)
		{
			int s = 0;
			for (int j = 1; j <= n; j++)
			{
				s = max(s, 0) + b[i2][j] - b[i1][j];
				z = max(z, s);
			}
		}
	}
	cout << z << endl;
	return 0;
}
