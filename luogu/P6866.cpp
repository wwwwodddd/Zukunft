#include <bits/stdc++.h>
using namespace std;
int n, m, z;
char s[120][120];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '*' && s[i + 1][j] != '*' && s[i][j + 1] != '*')
			{
				z++;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}