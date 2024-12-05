#include <bits/stdc++.h>
using namespace std;
char a[2020], b[2020];
int f[2020][2020];
int n, m;
int main()
{
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				f[i][j] = i + j;
			}
			else if (a[i] == b[j])
			{
				f[i][j] = f[i - 1][j - 1];
			}
			else
			{
				f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
			}
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}