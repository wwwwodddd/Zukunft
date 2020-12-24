#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
char s[100020], t[] = "ACGT";
int f[100020][4][4][4];
int n;
void inc(int &x, int y)
{
	x = (x + y) % p;
}
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	for (int c = 0; c < 4; c++)
	{
		if (s[0] != '?' && s[0] != t[c])
		{
			continue;
		}
		for (int j = 0; j < 4; j++)
		{
			f[1][j][c][c] = 1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (s[i] != '?' && s[i] != t[c])
			{
				continue;
			}
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					for (int l = 0; l < 4; l++)
					{
						if (l != c)
						{
							inc(f[i + 1][j][k][c], f[i][j][k][l]);
						}
						if (j == l)
						{
							inc(f[i + 1][k][c][c], f[i][j][k][l]);
						}
					}
				}
			}
		}
	}
	int z = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			inc(z, f[n][j][k][j]);
		}
	}
	printf("%d\n", z);
	return 0;
}