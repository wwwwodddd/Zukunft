#include <bits/stdc++.h>
using namespace std;
int n, x, ss;
int s[500020];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		int v = 0;
		while (ss > 0 && s[ss] <= x)
		{
			if (s[ss] == x)
			{
				v = 1;
			}
			ss--;
			z++;
		}
		if (ss && v == 0)
		{
			z++;
		}
		s[++ss] = x;
	}
	printf("%lld\n", z);
	return 0;
}