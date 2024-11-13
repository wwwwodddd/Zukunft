#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
char c[120][120];
int f[120][120][120];
int s[120][120];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = n; i > 0; i--)
	{
		scanf("%s", c[i] + 1);
	}
	f[0][1][m] = 1;
	int z = 1;
	for (int h = 1; h <= n; h++)
	{
		memcpy(s, f[h - 1], sizeof s);
		for (int i = 1; i <= m; i++)
		{
			for (int j = m; j > 0; j--)
			{
				s[i][j] = (s[i][j] + s[i - 1][j]) % p;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = m; j > 0; j--)
			{
				s[i][j] = (s[i][j] + s[i][j + 1]) % p;
			}
		}
		for (int i = m; i > 0; i--)
		{
			for (int j = i; j <= m; j++)
			{
				if (c[h][j] == 'X')
				{
					break;
				}
				f[h][i][j] = s[i][j];
			}
		}
	}
	for (int h = 1; h <= n; h++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = i; j <= m; j++)
			{
				z = (z + f[h][i][j]) % p;
			}
		}
	}
	cout << z << endl;
	return 0;
}