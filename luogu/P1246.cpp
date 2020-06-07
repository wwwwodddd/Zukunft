#include <bits/stdc++.h>
using namespace std;
int n, c[27][27];
char s[27];
int gao()
{
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		z += c[26][i];
	}
	for (int i = 0; i < n; i++)
	{
		int p = i > 0 ? s[i - 1] + 1 : 'a';
		if (p > s[i])
		{
			return 0;
		}
		for (int j = p; j < s[i]; j++)
		{
			z += c['z' - j][n - i - 1];
		}
	}
	return z;
}
int main()
{
	for (int i = 0; i <= 26; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	scanf("%s", s);
	n = strlen(s);
	printf("%d\n", gao());
	return 0;
}