#include <bits/stdc++.h>
using namespace std;
int n, m, mo;
int f[3][100010][11];
vector<int> a[100020];
int mul(int x, int y)
{
	if (!x || !y)
	{
		return 0;
	}
	int re = (long long)x * y % mo;
	if (!re)
	{
		re = mo;
	}
	return re;
}
int mod(int x)
{
	if (!x)
	{
		return 0;
	}
	x %= mo;
	if (!x)
	{
		x = mo;
	}
	return x;
}
void tdp(int x, int y)
{
	for (int i = 0; i < 11; i++)
	{
		f[0][x][i] = 1;
	}
	for (int i : a[x])
	{
		if (i == y)
		{
			continue;
		}
		tdp(i, x);
		for (int k = 0; k < 11; k++)
		{
			int t1 = mod(f[0][i][k] + f[1][i][k]);
			int t2 = 0;
			if (k)
			{
				t2 = mod(f[0][i][k - 1] + f[1][i][k - 1] + f[2][i][k - 1]);
			}
			f[2][x][k] = mod(mul(f[2][x][k], t2) + mul(f[1][x][k], t1));
			f[1][x][k] = mod(mul(f[1][x][k], t2) + mul(f[0][x][k], t1));
			f[0][x][k] = mul(f[0][x][k], t2);
		}
	}
	return;
}
int main()
{
	scanf("%d%d%d", &n, &m, &mo);
	if (m != n - 1)
	{
		puts("-1\n-1");
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	tdp(1, -1);
	for (int i = 0; i < 11; i++)
	{
		if (f[0][1][i] + f[1][1][i] + f[2][1][i] > 0)
		{
			printf("%d\n%d\n", i, (f[0][1][i] + f[1][1][i] + f[2][1][i]) % mo);
			break;
		}
	}
	return 0;
}