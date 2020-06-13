#include <bits/stdc++.h>
using namespace std;
int n;
char c[] = "yizhong";
char s[110][110];
char z[110][110];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool ok(int i, int j, int k)
{
	for (int l = 0; l < 7; l++)
	{
		if (i + dx[k] * l < 0 || j + dy[k] * l < 0 || s[i + dx[k] * l][j + dy[k] * l] != c[l])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0 ; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			z[i][j] = '*';
		}
	}
	for (int i = 0 ; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (ok(i, j, k))
				{
					for (int l = 0; l < 7; l++)
					{
						z[i + dx[k] * l][j + dy[k] * l] = c[l];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", z[i]);
	}
	return 0;
}