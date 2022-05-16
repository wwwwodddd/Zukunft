#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		bitset<51000> f;
		scanf("%d%d", &n, &m);
		f[0] = 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			f |= f << x;
		}
		for (int i = 0; i < 1000; i++)
		{
			if (f[m + i])
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}