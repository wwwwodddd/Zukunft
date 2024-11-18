#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[5020];
char c[5020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%s", &n, s);
		for (int i = 0; i < n; i++)
		{
			s[i] ^= '1';
		}
		for (int k = n; k > 0; k--)
		{
			memset(c, 0, sizeof c);
			for (int i = 0; i < n; i++)
			{
				c[i % k] ^= s[i];
			}
			bool ok = true;
			for (int i = 0; i < k; i++)
			{
				if (c[i] != c[0])
				{
					ok = false;
				}
			}
			if (ok)
			{
				printf("%d\n", k);
				break;
			}
		}
	}
	return 0;
}