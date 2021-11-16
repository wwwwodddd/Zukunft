#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z = 1;
int c[200020];
int f[200020];
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
		if (x != y)
		{
			f[x] = y;
			c[y] += c[x];
			z = max(z, c[y]);
		}
	}
	cout << z << endl;
	return 0;
}
