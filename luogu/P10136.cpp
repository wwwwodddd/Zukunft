#include <bits/stdc++.h>
using namespace std;
int n;
long a[10020];
long mn = 1e18;
set<int> s;
void div(long v)
{
	for (long i = 1; i * i <= v; i++)
	{
		if (v % i == 0)
		{
			if (i <= mn)
			{
				s.insert(i);
			}
			if (v / i <= mn)
			{
				s.insert(v / i);
			}
		}
	}
}
bool ok(int v)
{
	long x = -1, y = -1, z = -1;
	for (int i = 0; i < n; i++)
	{
		int q = a[i] % v;
		if (q != x)
		{
			if (x == -1)
			{
				x = q;
			}
			else
			{
				if (q != y)
				{
					if (y == -1)
					{
						y = q;
					}
					else
					{
						if (q != z)
						{
							if (z == -1)
							{
								z = q;
							}
							else
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mn = min(mn, a[i] / 4);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	if (n < 4)
	{
		cout << mn * (mn + 1) / 2 << endl;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < i; j++)
			{
				div(a[i] - a[j]);
			}
		}
		long z = 0;
		for (int i : s)
		{
			if (ok(i))
			{
				z += i;
			}
		}
		printf("%ld\n", z);
	}
	return 0;
}