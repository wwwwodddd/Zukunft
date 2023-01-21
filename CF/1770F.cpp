#include <bits/stdc++.h>
using namespace std;
long long n, x, y, z;
int main()
{
	cin >> n >> x >> y;
	for (int yy = y; yy > 0; --yy &= y)
	{
		for (int i = 0; i < 20; i++)
		{
			if (yy >> i & 1)
			{
				if (((n * yy - (1 << i)) & (x - (1 << i))) == (x - (1 << i)))
				{
					z ^= 1 << i;
				}
			}
		}
	}
	cout << n % 2 * z << endl;
	return 0;
}