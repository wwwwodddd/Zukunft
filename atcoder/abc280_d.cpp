#include <bits/stdc++.h>
using namespace std;
long long k;
long long z;
long long F(long long p, long long c)
{
	// find n! % (p ** c) == 0
	for (long long i = p;; i += p)
	{
		long long j = i;
		while (j % p == 0)
		{
			c--;
			j /= p;
		}
		if (c <= 0)
		{
			return i;
		}
	}
}
int main()
{
	cin >> k;
	for (long long i = 2; i * i <= k; i++)
	{
		if (k % i == 0)
		{
			int c = 0;
			while (k % i == 0)
			{
				k /= i;
				c++;
			}
			z = max(z, F(i, c));			
		}
	}
	if (k > 1)
	{
		z = max(z, F(k, 1));
	}
	cout << z << endl;
	return 0;
}
