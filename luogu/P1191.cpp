#include <bits/stdc++.h>
using namespace std;
char c[2020];
int n, z;
int s[2020], ss;
int b[2020][2020];
int f[2020][2020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", c);
		for (int j = n - 1; j >= 0; j--)
		{
			if (c[j] == 'W')
			{
				b[i][j] = b[i][j + 1] + 1;
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		s[0] = 0;
		ss = 0;
		for (int i = 1; i <= n; i++)
		{
			while (b[s[ss]][j] > b[i][j])
			{
				ss--;
			}
			f[i][j] = f[s[ss]][j] + b[i][j] * (i - s[ss]);
			z += f[i][j];
			s[++ss] = i;
		}
	}
	printf("%d\n", z);
	return 0;
}