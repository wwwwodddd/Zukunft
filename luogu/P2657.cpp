#include <bits/stdc++.h>
using namespace std;
int f[15][15];
int a[15];
int F(int x)
{
	int re = 0, c = 0;
	for (; x > 0; x /= 10)
	{
		a[++c] = x % 10;
	}
	for (int i = 1; i <= c; i++)
	{
		for (int j = 1; j < (i < c ? 10 : a[c]); j++)
		{
			re += f[i][j];
		}
	}
	for (int i = c - 1; i > 0; i--)
	{
		for (int j = 0; j < a[i]; j++)
		{
			if (abs(j - a[i + 1]) >= 2)
			{
				re += f[i][j];
			}
		}
		if (abs(a[i] - a[i + 1]) < 2)
		{
			break;
		}
	}
	return re;
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		f[1][i] = 1;
	}
	for (int i = 2; i < 11; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (abs(j - k) >= 2)
				{
					f[i][j] += f[i - 1][k];
				}
			}
		}
	}
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d\n", F(y + 1) - F(x));
	return 0;
}