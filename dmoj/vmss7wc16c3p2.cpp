#include <bits/stdc++.h>
using namespace std;
int f[100020];
int n, m, x, y, s, t;
int F(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
}
int main()
{
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y)
		{
			f[x] = y;
		}
	}
	if (F(s) == F(t))
	{
		cout << "GO SHAHIR!" << endl;
	}
	else
	{
		cout << "NO SHAHIR!" << endl;
	}
	return 0;
}