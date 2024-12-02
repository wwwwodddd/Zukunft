#include <bits/stdc++.h>
using namespace std;
int t, n;
long long h[200020];
long long a[200020];
pair<int, int> b[200020];
long long floor(long long x, long long y)
{
	assert(y > 0);
	if (x % y == 0)
	{
		return x / y;
	}
	if (x > 0)
	{
		return x / y;
	}
	else
	{
		return x / y - 1;
	}
}
int kao()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &h[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(b, b + n);
	if (b[0].first != 0)
	{
		return -1;
	}
	long long L = 0, R = 2e18;
	for (int i = 1; i < n; i++)
	{
		if (b[i].first != i && b[i].first != b[i - 1].first)
		{
			return -1;
		}
		int x = b[i].second;
		int y = b[i - 1].second;
		long long dh = h[x] - h[y];
		long long da = a[y] - a[x];
		if (b[i].first == b[i - 1].first)
		{
			if (a[x] == a[y])
			{
				if (h[x] == h[y])
				{
				}
				else
				{
					return -1;
				}
			}
			else
			{
				// h[x] + a[x] * t == h[y] + a[y] * t
				if (dh % da != 0)
				{
					return -1;
				}
				else
				{
					L = max(L, dh / da);
					R = min(R, dh / da);
				}
			}
		}
		else
		{
			// h[x] - h[y] < (a[y] - a[x]) * t
			if (da == 0)
			{
				if (dh < 0)
				{
				}
				else
				{
					return -1;
				}
			}
			else if (da > 0)
			{
				// dh / da < t
				L = max(L, floor(dh, da) + 1);
			}
			else if (da < 0)
			{
				// dh / da > t
				R = min(R, floor(-dh - 1, -da));
			}
		}
	}
	if (L <= R)
	{
		return L;
	}
	else
	{
		return -1;
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		printf("%d\n", kao());
	}
	return 0;
}