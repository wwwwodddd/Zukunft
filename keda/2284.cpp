#include <bits/stdc++.h>
using namespace std;
int a[1000020], n;
int s[1000020], ss;
int z[1000020];
int main()
{
	// freopen("Interval minimum value.in", "r", stdin);
	// freopen("Interval minimum value.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n + 1; i++)
	{
		if (i <= n)
		{
			scanf("%d", &a[i]);
		}
		while (ss > 0 && a[i] < a[s[ss]])
		{
			z[i - s[ss - 1] - 1] = max(z[i - s[ss - 1] - 1], a[s[ss]]);
			ss--;
		}
		z[i - s[ss]] = max(z[i - s[ss]], a[i]);
		s[++ss] = i;
	}
	for (int i = n; i > 0; i--)
	{
		z[i] = max(z[i], z[i + 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", z[i], i == n ? '\n' : ' ');
	}
	return 0;
}