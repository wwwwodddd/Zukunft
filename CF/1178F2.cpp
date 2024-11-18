#include <bits/stdc++.h>
using namespace std;
int f[1020][1020];
int mn[1020][1020];
vector<int> c;
vector<int> p[1020];
int n, m, x, mod = 998244353;
int F(int l, int r)
{
	if (l > r)
	{
		return 1;
	}
	if (f[l][r] != -1)
	{
		return f[l][r];
	}
	f[l][r] = 0;
	int minc = mn[l][r];
	int ll = p[minc].front();
	int rr = p[minc].back();
	int left = 0;
	for (int k = l; k <= ll; k++)
	{
		left = (left + (long long)F(l, k - 1) * F(k, ll - 1)) % mod;
	}
	int right = 0;
	for (int k = rr; k <= r; k++)
	{
		right = (right + (long long)F(rr + 1, k) * F(k + 1, r)) % mod;
	}
	int mid = 1;
	for (int i = 1; i < p[minc].size(); i++)
	{
		mid = (long long)mid * F(p[minc][i - 1] + 1, p[minc][i] - 1) % mod;
	}
	//	cerr << l << ' ' << r << ' ' << left << ' ' << right << ' ' << mid << endl;
	f[l][r] = (long long)left * right % mod * mid % mod;
	return f[l][r];
}
int main()
{
	scanf("%d%d", &n, &m);
	c.push_back(0);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &x);
		if (x != c.back())
		{
			p[x].push_back(c.size());
			c.push_back(x);
		}
	}
	if (c.size() > 1010)
	{
		printf("0\n");
		return 0;
	}
	m = c.size() - 1;
	memset(f, -1, sizeof f);
	for (int i = 1; i <= m; i++)
	{
		mn[i][i] = c[i];
		for (int j = i + 1; j <= m; j++)
		{
			mn[i][j] = min(mn[i][j - 1], c[j]);
		}
	}
	printf("%d\n", F(1, m));
	return 0;
}