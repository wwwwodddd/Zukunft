#include <bits/stdc++.h>
using namespace std;
const int p = 9901;
int gao(int r, int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n % 2 == 0)
	{
		return gao(r * r % p, n / 2) * (r + 1) % p;
	}
	else
	{
		return (gao(r, n - 1) * r + 1) % p;
	}
}
int main()
{
	int a, b, z = 1;
	cin >> a >> b;
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			int c = 0;
			for (; a % i == 0; a /= i)
			{
				c++;
			}
			c *= b;
			z = z * gao(i % p, c + 1) % p;
		}
	}
	if (a > 1)
	{
		z = z * gao(a % p, b + 1) % p;
	}
	cout << z << endl;
	return 0;
}