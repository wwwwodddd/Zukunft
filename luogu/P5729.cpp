#include <bits/stdc++.h>
using namespace std;
int a[21][21][21];
int main()
{
	int w, x, h, q, x1, y1, z1, x2, y2, z2, c = 0;
	cin >> w >> x >> h >> q;
	for (int p = 0; p < q; p++)
	{
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for (int i = x1; i <= x2; i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				for (int k = z1; k <= z2; k++)
				{
					a[i][j][k] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= w; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			for (int k = 1; k <= h; k++)
			{
				c += !a[i][j][k];
			}
		}
	}
	cout << c << endl;
	return 0;
}