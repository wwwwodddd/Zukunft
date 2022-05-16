#include <bits/stdc++.h>
using namespace std;
int t, n, a[20];
double f[65537];
double S(int x, int y, int z)
{
	double s = (x + y + z) * 0.5;
	if (s >= x && s >= y && s >= z)
	{
		return sqrt(s * (s - x) * (s - y) * (s - z));
	}
	else
	{
		return 0;
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		memset(f, 0, sizeof f);
		for (int i = 0; i < 1 << n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
				{
					continue;
				}
				for (int k = 0; k < j; k++)
				{
					if (i >> k & 1)
					{
						continue;
					}
					for (int l = 0; l < k; l++)
					{
						if (i >> l & 1)
						{
							continue;
						}
						f[i | 1 << j | 1 << k | 1 << l] = max(f[i | 1 << j | 1 << k | 1 << l], f[i] + S(a[j], a[k], a[l]));
					}
				}
			}
		}
		printf("%.6f\n", f[(1 << n) - 1]);
	}
	return 0;
}