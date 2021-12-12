#include <bits/stdc++.h>
using namespace std;
int divisors(int x)
{
	int c = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0)
		{
			c++;
		}
	}
	return c;
}
int n, z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1 && divisors(i) == 8)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
