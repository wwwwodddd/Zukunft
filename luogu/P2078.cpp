#include <bits/stdc++.h>
using namespace std;
int n, m, p, q, x, y;
int f[20020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> m >> p >> q;
	for (int i = 0; i <= n + m; i++)
	{
		f[i] = i;
	}
	f[m - 1] = f[m + 1] = m;
	for (int i = 0; i < p + q; i++)
	{
		cin >> x >> y;
		x = F(x + m);
		y = F(y + m);
		f[x] = y;
	}
	x = y = 0;
	for (int i = 0; i < m; i++)
	{
		if (F(i) == F(m))
		{
			x++;
		}
	}
	for (int i = m + 1; i <= m + n; i++)
	{
		if (F(i) == F(m))
		{
			y++;
		}
	}
	cout << min(x, y) << endl;
	return 0;
}
