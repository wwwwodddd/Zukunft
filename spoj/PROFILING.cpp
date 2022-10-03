#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n, m;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		if (n > 0 && m == 0)
		{
			m += 2;
		}
		int x = 0, y = 1;
		for (int i = 0; i <= n - m; i++)
		{
			int z = (x + y) % p;
			x = y;
			y = z;
		}
		printf("%d\n", x);
	}
	return 0;
}