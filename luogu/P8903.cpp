#include <bits/stdc++.h>
using namespace std;
int n, a, b;
struct Cow
{
	int p, c, x;
} c[2020];
bool operator<(const Cow &a, const Cow &b)
{
	return a.x < b.x;
}
int f[2020][2020]; // use c[0..i-1]    j ice cream    max popularity
int g[2020][2020]; // use c[i..n-1]    j money        max popularity
int main()
{
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i].p >> c[i].c >> c[i].x;
	}
	sort(c, c + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			f[i + 1][j] = f[i][j];
			if (j >= c[i].x * c[i].c)
			{
				f[i + 1][j] = max(f[i + 1][j], f[i][j - c[i].x * c[i].c] + c[i].p);
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= a; j++)
		{
			g[i][j] = g[i + 1][j];
			if (j >= c[i].c)
			{
				g[i][j] = max(g[i][j], g[i + 1][j - c[i].c] + c[i].p);
			}
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= c[i].c && j <= a; j++)
		{
			if (b - (c[i].c - j) * c[i].x >= 0)
			{
				z = max(z, g[i + 1][a - j] + f[i][b - (c[i].c - j) * c[i].x] + c[i].p);
			}
		}
	}
	cout << z << endl;
	return 0;
}