#include <bits/stdc++.h>
using namespace std;
int n, x, c[2000020];
long long z = 0;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		c[x]++;
	}
	for (int i = 1; i < 2000020; i++)
	{
		c[i] += c[i - 1];
	}
	for (int i = 1; i < 1000010; i++)
	{
		int oc = 0;
		int ox = 0;
		int on = 0;
		int oz = 0;
		for (int j = i; j < 1000010; j += i)
		{
			if ((c[j + i - 1] - c[j - 1]) & 1)
			{
				if (!oc++)
				{
					on = j / i;
				}
				ox = j / i;
				oz = c[j + i - 1] - c[j - 1];
			}
		}
		if ((oc == 2 && on + 1 == ox) || (oc == 1 && ox == 1))
		{
			z += oz;
		}
	}
	printf("%lld\n", z);
	return 0;
}