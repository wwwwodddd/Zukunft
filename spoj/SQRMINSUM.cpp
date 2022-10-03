#include <bits/stdc++.h>
using namespace std;
int t, l, k;
int c[10020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &l, &k);
		int z = 0;
		for (int i = 1; i <= l; i++)
		{
			z += i;
			c[i] = 1;
		}
		for (int i = l; i > 0 && k > 0; i--)
		{
			int t = min(k, c[i]);
			int j = sqrt(i);
			c[i] -= t;
			k -= t;
			c[j] += t;
			z += (j - i) * t;
		}
		printf("%d\n", z);
	}
	return 0;
}