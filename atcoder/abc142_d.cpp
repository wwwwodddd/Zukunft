#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long gcd(long long x, long long y)
{
	return y ? gcd(y, x % y) : x;
}
int main()
{
	cin >> a >> b;
	long long g = gcd(a, b);
	int c = 0;
	for (long long i = 2; i * i <= g; i++)
	{
		if (g % i == 0)
		{
			while (g % i == 0)
			{
				g /= i;
			}
			c++;
		}
	}
	if (g > 1)
	{
		c++;
	}
	cout << c + 1 << endl;
	return 0;
}
