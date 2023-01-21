#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int c[1000020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		fill(c, c + 4 * n, 0);
		int s = 0;
		c[s]++;
		long long z = n * (n + 1LL) / 2;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			s ^= x;
			for (int j = 0; j * j < 2 * n; j++)
			{
				z -= c[s ^ (j * j)];
			}
			c[s]++;
		}
		cout << z << endl;
	}
	return 0;
}