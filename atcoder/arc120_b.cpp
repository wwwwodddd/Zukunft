#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[520][520];
int r[1020], b[1020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'R')
			{
				r[i + j] = 1;
			}
			if (s[i][j] == 'B')
			{
				b[i + j] = 1;
			}
		}
	}
	int z = 1;
	for (int i = 0; i < n + m - 1; i++)
	{
		z = z * (2 - r[i] - b[i]) % 998244353;
	}
	printf("%d\n", z);
	return 0;
}
