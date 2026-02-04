#include <bits/stdc++.h>
using namespace std;
int t;
long long x, m;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> x >> m;
		long long z = 0;
		for (long long d = 0; d <= min(m, x) + x; d++)
		{
			if ((d ^ x) <= m && d != x)
			{
				if (d % x == 0 || d % (d ^ x) == 0)
				{
					z++;
				}
			}
		}
		long long l = min(m, x) + x;
		if (l < m - x)
		{
			z += (m - x) / x - l / x;
			l = (m - x) / x * x;
		}
		for (long long d = l + 1; d <= m + x; d++)
		{
			if ((d ^ x) <= m)
			{
				if (d % x == 0)
				{
					z++;
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}