#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int a[30];
void dfs(int d, int b)
{
	if (d == n)
	{
		z++;
		return;
	}
	dfs(d + 1, b);
	if ((a[d] & b) == 0)
	{
		dfs(d + 1, b | 1 << d);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		a[x] |= 1 << y;
		a[y] |= 1 << x;
	}
	dfs(0, 0);
	cout << z << endl;
	return 0;
}
