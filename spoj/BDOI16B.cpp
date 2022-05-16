#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int F(int n, int p)
{
	return n ? F(n / p, p) + n / p : 0;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d", &n, &k);
		int z = n;
		for (int i = 2; i * i <= k; i++)
		{
			if (k % i == 0)
			{
				int c = 0;
				for (; k % i == 0; k /= i)
				{
					c++;
				}
				z = min(z, F(n, i) / c);
			}
		}
		if (k > 1)
		{
			z = min(z, F(n, k));
		}
		printf("Case %d: %d\n", tt, z);
	}
	return 0;
}