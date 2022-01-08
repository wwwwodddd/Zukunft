#include <bits/stdc++.h>
using namespace std;
long long x, z = 1e18;
int main()
{
	cin >> x;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int d = j - i, e = i;
			long long y = 0;
			for (int k = 0; k < 18; k++)
			{
				if (e < 0 || e > 9)
				{
					break;
				}
				y = y * 10 + e;
				e += d;
				if (y >= x)
				{
					z = min(z, y);
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}
