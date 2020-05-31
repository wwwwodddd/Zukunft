#include <bits/stdc++.h>
using namespace std;
int n, m, z, a[20];
bitset<2016> f;
void dfs(int x, int y)
{
	if (x == n)
	{
		z = max(z, int(f.count()));
		assert(y == n - m);
	}
	if (x - y < m)
	{
		dfs(x + 1, y);
	}
	if (y < n - m)
	{
		bitset<2016> g = f;
		f |= f << a[x];
		dfs(x + 1, y + 1);
		f = g;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	f[0] = 1;
	dfs(0, 0);
	cout << z - 1 << endl;
	return 0;
}