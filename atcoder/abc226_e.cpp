#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, x, y;
int f[200020];
int c[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y)
		{
			f[x] = y;
			c[y] += c[x];
		}
		else
		{
			c[x]++;
		}
	}
	int z = 1;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			if (c[i] == 1)
			{
				z = z * 2 % p;
			}
			else
			{
				z = 0;
			}
		}
	}
	cout << z << endl;
	return 0;
}
