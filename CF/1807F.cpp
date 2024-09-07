#include <bits/stdc++.h>
using namespace std;
int t, n, m;
string d;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int i1, j1, i2, j2;
		cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
		int ans = -1;
		for (int z = 0; z < 2 * n + 2 * m + 2; z++)
		{
			// cout << i1 << " " << j1 << " " << d << " " << z << endl;
			if (d == "DR")
			{
				if (i2 >= i1 && j2 >= j1 && i2 - i1 == j2 - j1)
				{
					ans = z;
					break;
				}
				int s = min(n - i1, m - j1);
				i1 += s;
				j1 += s;
				if (i1 == n)
				{
					d[0] = 'U';
				}
				if (j1 == m)
				{
					d[1] = 'L';
				}
			}
			else if (d == "DL")
			{
				if (i2 >= i1 && j2 <= j1 && i2 - i1 == j1 - j2)
				{
					ans = z;
					break;
				}
				int s = min(n - i1, j1 - 1);
				i1 += s;
				j1 -= s;
				if (i1 == n)
				{
					d[0] = 'U';
				}
				if (j1 == 1)
				{
					d[1] = 'R';
				}
			}
			else if (d == "UR")
			{
				if (i2 <= i1 && j2 >= j1 && i1 - i2 == j2 - j1)
				{
					ans = z;
					break;
				}
				int s = min(i1 - 1, m - j1);
				i1 -= s;
				j1 += s;
				if (i1 == 1)
				{
					d[0] = 'D';
				}
				if (j1 == m)
				{
					d[1] = 'L';
				}
			}
			else if (d == "UL")
			{
				if (i2 <= i1 && j2 <= j1 && i1 - i2 == j1 - j2)
				{
					ans = z;
					break;
				}
				int s = min(i1 - 1, j1 - 1);
				i1 -= s;
				j1 -= s;
				if (i1 == 1)
				{
					d[0] = 'D';
				}
				if (j1 == 1)
				{
					d[1] = 'R';
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}