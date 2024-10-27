#include <bits/stdc++.h>
using namespace std;
int n, b, p;
int c[200020];
long long f[200020];
vector<int> a[200020];
set<int> z;
set<long long> g;
void dfs1(int x, int y)
{
	f[x] = 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs1(i, x);
			f[x] = (f[x] + f[i] * b) % p;
		}
	}
}
void dfs2(int x, int y)
{
	if (g.find(f[x]) == g.end())
	{
		z.erase(x);
	}
	for (int i : a[x])
	{
		if (i != y)
		{
			f[i] = (f[i] + (f[x] - f[i] * b % p + p) * b % p) % p;
			dfs2(i, x);
		}
	}
}
void gao(int base, int mod)
{
	b = base;
	p = mod;
	long long s = 0, t = 1;
	for (int i = n; i >= 0; i--)
	{
		s = (s * b + c[i]) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		g.insert((s + t) % p);
		t = t * b % p;
	}
	dfs1(1, 0);
	dfs2(1, 0);
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x;
		cin >> x;
		c[x]++;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		z.insert(i);
	}
	gao(131, 1000000007);
	gao(1313, 1 << 30);
	gao(13131, 1000000009);
	gao(1313131, 998244353);
	cout << z.size() << endl;
	for (int i : z)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}