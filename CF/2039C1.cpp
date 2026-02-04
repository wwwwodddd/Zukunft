#include <bits/stdc++.h>
using namespace std;
int t, x;
long long m;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> x >> m;
		int z = 0;
		for (long long d = 1; d < x; d++)
		{
			long long y = x ^ d;
			if (y <= m && (x % d == 0 || y % d == 0))
			{
				z++;
			}
		}
		cout << z << endl;
	}
	return 0;
}