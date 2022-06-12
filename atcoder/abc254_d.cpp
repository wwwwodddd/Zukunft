#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int z = n;
	for (int y = 2; y * y <= n; y++)
	{
		int c = 0;
		for (int x = 1; x < y; x++)
		{
			if (__gcd(x, y) == 1)
			{
				c++;
			}
		}
//		c = phi(y)
		z += n / y / y * 2 * c;
	}
	cout << z << endl;
	return 0;
}
