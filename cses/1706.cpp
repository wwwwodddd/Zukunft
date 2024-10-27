#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[100020];
int c[100020];
bitset<100020> b;
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
		c[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x = F(x);
		y = F(y);
		c[y] += c[x];
		c[x] = 0;
		f[x] = y;
	}
	b[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (c[i])
		{
			b |= b << c[i];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << b[i];
	}
	return 0;
}