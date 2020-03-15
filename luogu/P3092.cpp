#include <bits/stdc++.h>
using namespace std;
int a[16];
int s[100001];
int f[65536];
int n, m, z = -1;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
	}
	for (int i = 0; i < 1 << n; i++)
	{
		int t = 0;
		for (int j = 0; j < n; j++)
		{
			if (~i >> j & 1)
			{
				int l = upper_bound(s, s + m + 1, s[f[i]] + a[j]) - s - 1;
				f[i | 1 << j] = max(f[i | 1 << j], l);
				t += a[j];
			}
		}
		if (f[i] == m)
		{
			z = max(z, t);
		}
	}
	printf("%d\n", z);
	return 0;
}