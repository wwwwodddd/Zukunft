#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[100020];
long long b[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		long long e = 0, o = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i & 1)
			{
				o += a[i];
			}
			else
			{
				e += a[i];
			}
		}
		long long z = -1;
		if (n & 1)
		{
			int f = 1;
			long long d = e - o;
			if (d >= 0)
			{
				for (int i = 0; i < n - 1; i++)
				{
					if (a[i] < d)
					{
						f = 0;
					}
					else
					{
						b[i] = a[i] - d;
						a[i + 1] -= b[i];
						a[i] -= b[i];
					}
				}
				if (f)
				{
					assert(a[n - 1] == d);
					z = (e + o - d * n);
				}
			}
		}
		else
		{
			if (e == o)
			{
				int f = 1;
				for (int i = 0; i < n - 1; i++)
				{
					if (a[i] < 0)
					{
						f = 0;
					}
					else
					{
						b[i] = a[i];
						a[i + 1] -= b[i];
						a[i] -= b[i];
					}
				}
				if (f)
				{
					assert(a[n - 1] == 0);
					long long d = 1e9;
					for (int i = 0; i < n; i += 2)
					{
						d = min(d, b[i]);
					}
					z = (e + o - d * n);
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}
