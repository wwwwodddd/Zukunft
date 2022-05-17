#include <bits/stdc++.h>
using namespace std;
int n, k, l, p, q;
int f[200020];
int g[200020];
map<pair<int, int>, int> a;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int G(int x)
{
	return g[x] != x ? g[x] = G(g[x]) : x;
}
int main()
{
	cin >> n >> k >> l;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		g[i] = i;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> p >> q;
		f[F(p)] = F(q);
	}
	for (int i = 0; i < l; i++)
	{
		cin >> p >> q;
		g[G(p)] = G(q);
	}
	for (int i = 1; i <= n; i++)
	{
		a[make_pair(F(i), G(i))]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[make_pair(F(i), G(i))] << " ";
	}
	return 0;
}
