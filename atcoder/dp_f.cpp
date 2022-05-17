#include <bits/stdc++.h>
using namespace std;
char s[3020];
char t[3020];
char z[3020];
int zc;
int f[3020][3020];
int p[3020][3020];
int main()
{
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1);
	int m = strlen(t + 1);
//	reverse(s + 1, s + 1 + n);
//	reverse(t + 1, t + 1 + m);
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
//			printf("%d ", f[i][j]);
		}
//		printf("\n");
	}
	int x = n;
	int y = m;
	while (x > 0 && y > 0)
	{
//		cout << x << " " << y << " " << endl;
		if (s[x] == t[y])
		{
			z[zc++] = t[y];
			x--;
			y--;
		}
		else if (f[x][y] == f[x - 1][y])
		{
			x--;
		}
		else if (f[x][y] == f[x][y - 1])
		{
			y--;
		}
	}
	for (int i = zc - 1; i >= 0; i--)
	{
		printf("%c", z[i]);
	}
	printf("\n");
	return 0;
}
