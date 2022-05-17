#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int f[200020];
int c[200020];
int p[200020];
int q[200020];
int g[200020] = {2, 1};
long long z = 1;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x == y)
	{
		return;
	}
	f[x] = y;
	c[y] += c[x];
}
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		g[i] = (g[i - 1] + g[i - 2]) % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> q[i];
		U(p[i], q[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			z = z * g[c[i]] % mod;
		}
	}
	cout << z << endl;
	return 0;
}
