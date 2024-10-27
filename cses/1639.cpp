#include <bits/stdc++.h>
using namespace std;
char s[5020];
char t[5020];
int n, m;
int f[5020][5020];
int main()
{
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				f[i][j] = i + j;
			}
			else if (s[i] == t[j])
			{
				f[i][j] = f[i - 1][j - 1];
			}
			else
			{
				f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
			}
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}