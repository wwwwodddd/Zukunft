#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<int> a[100020];
long long f[100020], sf;
long long g[100020], sg;
int n, m, x, y;
void dfs(int x)
{
	if (f[x] > 0)
	{
		return;
	}
	f[x] = 1;
	g[x] = 0;
	for (int i: a[x])
	{
		dfs(i);
		f[x] = (f[x] + f[i]) % mod;
		g[x] = (g[x] + g[i] + f[i]) % mod;
	}
}
long long pw(long long x, long long y)
{
	long long re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % mod;
		}
		x = x * x % mod;
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i);
		sf = (sf + f[i]) % mod;
		sg = (sg + g[i]) % mod;
	}
	printf("%lld\n", sg * pw(sf, mod - 2) % mod);
	return 0;
}