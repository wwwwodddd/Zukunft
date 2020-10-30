#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, m;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		int g = 0, x;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			g = __gcd(g, x);
		}
		int z = m / g * g;
		for (int i = 2; i * i <= g; i++)
		{
			if (g % i == 0)
			{
				z = max(z, m / i * i);
				z = max(z, m / (g/i) * (g/i));
			}
		}
		printf("%d\n", z);
	}
	return 0;
}