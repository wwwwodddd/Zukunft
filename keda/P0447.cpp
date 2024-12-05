#include <bits/stdc++.h>
using namespace std;
char s[3020];
char t[3020];
int f[3020][3020];
int main()
{
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1);
	int m = strlen(t + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i] == t[j])
			{
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}