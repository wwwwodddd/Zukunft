#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int c0 = 0, c1 = 0;
		long long z = 0, s = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == 1)
			{
				c1++;
			}
			else
			{
				s += c1;
			}
		}
		z = s;
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] == 1)
			{
				c1--;
				// 1 to 0
				// z = max(z, s - (right 0) + (left 1))
				z = max(z, s - c0 + c1);
			}
			if (a[i] == 0)
			{
				// 0 to 1
				// z = max(z, s - (left 1) + (right 0))
				z = max(z, s - c1 + c0);
				c0++;
			}
		}
		cout << z << endl;
	}
	return 0;
}
