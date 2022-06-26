#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long x;
unsigned long long f[70][1024];
int len(unsigned long long n)
{
	int c = 0;
	while (n > 0)
	{
		c++;
		n /= 10;
	}
	return c;
}
int wei(unsigned long long n)
{
	int b = 0;
	while (n > 0)
	{
		b |= 1 << n % 10;
		n /= 10;
	}
	return b;
}
int main()
{
	cin >> n >> x;
	f[0][wei(x)] = x;
	for (int i = 0; i < 69; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			if (f[i][j] == 0)
			{
				continue;
			}
			for (int k = 0; k < 10; k++)
			{
				if (j >> k & 1)
				{
					// cout << i << " " << j << " " << k << " " << f[i][j] * k << endl;
					unsigned long long &t = f[i + 1][wei(f[i][j] * k)];
					t = max(t, f[i][j] * k);
					if (len(t) == n)
					{
						cout << i + 1 << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}