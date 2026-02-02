#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int a[120];
int f[30020];
int g[30020];
void gao(int x, int y)
{
	for (int i = m; i >= x; i--)
	{
		f[i] = min(f[i], f[i - x] + y);
	}
}
int main()
{
	cin >> n >> t;
	m = t + 15000;
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	f[0] = 0;
	g[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = a[i]; j <= m; j += 1)
		{
			g[j] = min(g[j], g[j - a[i]] + 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		int u;
		cin >> u;
		for (int j = 1; j < u; j *= 2)
		{
			u -= j;
			gao(j * a[i], j);
		}
		gao(u * a[i], u);
	}
	int z = 1e9;
	for (int i = t; i < m; i++)
	{
		z = min(z, f[i] + g[i - t]);
	}
	if (z == 1e9)
	{
		z = -1;
	}
	cout << z << endl;
	return 0;
}