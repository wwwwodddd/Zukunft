#include <bits/stdc++.h>
using namespace std;
int t, n, m, p, x, y;
int a[262144];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> p;
		m = 1 << 32 - __builtin_clz(n);
		fill(a, a + 2 * m, 1);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &x, &y);
			if (x == 1)
			{
				a[m + i] = y;
				y = i;
			}
			else
			{
				a[m + y] = 1;
			}
			for (int j = m + y; j /= 2;)
			{
				a[j] = (long long)a[j * 2] * a[j * 2 + 1] % p;
			}
			printf("%d\n", a[1]);
		}
	}
	return 0;
}