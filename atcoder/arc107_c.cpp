#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m;
int a[50][50];
int f[100];
int c[100];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		f[x] = y;
		c[y] += c[x];
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 2 * n; i++)
	{
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int v = 1;
			for (int k = 0; k < n; k++)
			{
				if (a[i][k] + a[j][k] > m)
				{
					v = 0;
					break;
				}
			}
			if (v)
			{
				U(i, j);
			}
			v = 1;
			for (int k = 0; k < n; k++)
			{
				if (a[k][i] + a[k][j] > m)
				{
					v = 0;
					break;
				}
			}
			if (v)
			{
				U(i + n, j + n);
			}
		}
	}
	long long z = 1;
	for (int i = 0; i < 2 * n; i++)
	{
		if (f[i] == i)
		{
			for (int j = 1; j <= c[i]; j++)
			{
				z = z * j % p;
			}
		}
	}
	cout << z << endl;
	return 0;
}
