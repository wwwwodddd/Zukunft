#include <bits/stdc++.h>
using namespace std;
char s[100020];
int a[20][20];
int f[1048577];
int v[256], c;
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (!v[s[i]])
		{
			v[s[i]] = ++c;
		}
		s[i] = v[s[i]];
		if (i > 0)
		{
			a[s[i] - 1][s[i - 1] - 1]++;
		}
	}
	for (int i = 0; i < 1 << c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (~i >> j & 1)
			{
				int s = 0;
				for (int k = 0; k < c; k++)
				{
					if (i >> k & 1)
					{
						s += a[j][k];
					}
				}
				f[i | 1 << j] = max(f[i | 1 << j], f[i] + s);
			}
		}
	}
	printf("%d\n", n - f[(1 << c) - 1]);
	return 0;
}