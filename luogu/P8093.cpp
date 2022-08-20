#include <bits/stdc++.h>
using namespace std;
int t;
long long x, y;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> x >> y;
		long long z = 1e18;
		long long c = 0;
		while (true)
		{
			if (x <= y)
			{
				z = min(z, c + y - x);
				if (x == y)
				{
					break;
				}
				if (y % 2 == 0)
				{
					y /= 2;
					c++;
				}
				else
				{
					y--;
					c++;
				}
			}
			else
			{
				if (x % 2 == 0)
				{
					x /= 2;
					c++;
				}
				else
				{
					x++;
					c++;
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}
