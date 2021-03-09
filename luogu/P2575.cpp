#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			int v[21] = {}, c = 0, u = m % 2;
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &x);
				v[x] = 1;
			}
			for (int j = 1; j <= 20; j++)
			{
				if (v[j])
				{
					c++;
				}
				else
				{
					if (u)
					{
						z ^= c;
					}
					u ^= 1;
					c = 0;
				}
			}
		}
		puts(z ? "YES" : "NO");
	}
	return 0;
}