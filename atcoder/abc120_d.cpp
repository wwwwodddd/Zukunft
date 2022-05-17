#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[100020];
int f[100020];
int x[100020];
int y[100020];
long long z[100020];
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
		cin >> x[i] >> y[i];
	}
	for (int i = m - 1; i >= 0; i--)
	{
		z[i] = z[i + 1];
		x[i] = F(x[i]);
		y[i] = F(y[i]);
		if (x[i] != y[i])
		{
			f[x[i]] = y[i];
			z[i] += (long long)c[x[i]] * c[y[i]];
			c[y[i]] += c[x[i]];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << z[0] - z[i] << endl;
	}
	return 0;
}
