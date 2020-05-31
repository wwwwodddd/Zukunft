#include <bits/stdc++.h>
using namespace std;
char s[60];
int f[60][60];
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = n; i > 0; i--)
	{
		f[i][i] = 1;
		for (int j = i + 1; j <= n; j++)
		{
			f[i][j] = f[i][j-1] + (s[i] != s[j]);
			for (int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
			}
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}