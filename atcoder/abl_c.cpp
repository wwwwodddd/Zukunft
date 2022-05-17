#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> m;
	int c = n;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y)
		{
			c--;
			f[x] = y;
		}
	}
	cout << c - 1 << endl;
	return 0;
}
