#include <bits/stdc++.h>
using namespace std;
int l, r;
int c[33][33];
int S(int n, int m) // n个位置，选 <= m 个
{
	int re = 0;
	for (int i = 0; i <= m; i++)
	{
		re += c[n][i];
	}
	return re;
}
int F(int n) // < n
{
	int re = 0;
	for (int i = 1; n >> i; i++)
	{
		re += S(i-1, i/2-1);
	}
	bool v = false;
	int cnt = 0;
	for (int i = 31; i >= 0; i--)
	{
		if (n >> i & 1)
		{
			if (v)
			{
				re += S(i, (i - cnt + 1) >> 1);
			}
			cnt++;
			v = true;
		}
		else
		{
			if (v)
			{
				cnt--;
			}
		}
	}
	return re;
}
bool R(int x)
{
	int cnt = 0;
	for (int i = 0; x >> i; i++)
	{
		if (x >> i & 1)
		{
			cnt++;
		}
		else
		{
			cnt--;
		}
	}
	return cnt <= 0;
}
int G(int n)
{
	int re = 0;
	for (int i = 1; i < n; i++)
	{
		if (R(i))
		{
			re++;
		}
	}
	return re;
}
int main()
{
	for (int i = 0; i < 33; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	scanf("%d%d", &l, &r);
	printf("%d\n", F(r + 1) - F(l));
	return 0;
}