#include <bits/stdc++.h>
using namespace std;
int n, m, l;
char c[100020];
int s[100020][30];
int f[100020][30];
int a[30][30];
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	scanf("%s", c + 1);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int k = 0; k < m; k++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] > a[i][k] + a[k][j])
				{
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s[i][j] = s[i - 1][j] + a[c[i] - 'a'][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			f[i][j] = f[i - 1][j] + a[c[i] - 'a'][j];
		}
		if (i >= l)
		{
			int tmp = 1e9;
			for (int j = 0; j < m; j++)
			{
				tmp = min(tmp, f[i - l][j] + s[i][j] - s[i - l][j]);
			}
			for (int j = 0; j < m; j++)
			{
				f[i][j] = min(f[i][j], tmp);
			}
			if (i == n)
			{	
				printf("%d\n", tmp);
			}
		}
	}
	return 0;
}