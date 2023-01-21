#include <bits/stdc++.h>
using namespace std;
const int p = 998244353, inv2 = (p + 1) / 2;
typedef long long ll;
int n, m;
vector<int> a[300020];
int u[300020];
int v[300020];
int f[300020];
int b[300020];
int s[300020];
ll z;
ll pw(ll x, ll y)
{
	ll re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
void dfs(int x, int y)
{
	f[x] = y;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			s[x] += s[i];
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		b[x] = s[x] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		a[u[i]].push_back(v[i]);
		a[v[i]].push_back(u[i]);
	}
	dfs(1, 0);
	for (int i = 1; i < n; i++)
	{
		if (u[i] == f[v[i]])
		{
			swap(u[i], v[i]);
		}
		ll us = s[u[i]], vs = m - s[u[i]];
		ll puv = b[u[i]] * (1LL + p - b[v[i]]) % p * inv2 % p;
		ll pvu = b[v[i]] * (1LL + p - b[u[i]]) % p * inv2 % p;
		z = (z + us * vs % p * (1 - puv - pvu + p + p)) % p;
		z = (z + (vs + 1) * (us - 1) % p * puv) % p;
		z = (z + (vs - 1) * (us + 1) % p * pvu) % p;
		b[u[i]] = b[v[i]] = (ll)(b[u[i]] + b[v[i]]) * inv2 % p;
	}
	printf("%lld\n", z * pw(m * (m - 1LL) / 2 % p, p - 2) % p);
	return 0;
}