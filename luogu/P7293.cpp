#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
int t, n, m, x, y;
vector<int> a[100020];
int d[2][100020];
int c[100020];
vector<pair<int, int> > f[3];
queue<pair<int, int> > q;
ll pw(ll x, ll y)
{
	ll re = 1;
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
ll gao(int x)
{
	sort(f[x].begin(), f[x].end());
	int zeros = t;
	ll ans = 0, mul = 1;
	memset(c, 0, sizeof c);
	for (pair<int, int> i: f[x])
	{
		if (i.first == 0x3f3f3f3f)
		{
			break;
		}
		if (c[i.second])
		{
			mul = mul * pw(c[i.second], mod - 2) % mod;
		}
		else
		{
			zeros--;
		}
		if (zeros == 0)
		{
			ans = (ans + i.first * mul) % mod;
		}
		mul = mul * ++c[i.second] % mod;
	}
	return ans;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		memset(d, 0x3f, sizeof d);
		d[0][1] = 0;
		q.push(make_pair(0, 1));
		while (q.size())
		{
			pair<int, int> u = q.front();
			q.pop();
			for (int i: a[u.second])
			{
				if (d[u.first ^ 1][i] == 0x3f3f3f3f)
				{
					d[u.first ^ 1][i] = d[u.first][u.second] + 1;
					q.push(make_pair(u.first ^ 1, i));
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			f[0].push_back(make_pair(d[0][i], tt));
			f[1].push_back(make_pair(d[1][i], tt));
			f[2].push_back(make_pair(max(d[0][i], d[1][i]), tt));
		}
	}
	ll z = (gao(0) + gao(1) + mod - gao(2)) % mod;
	printf("%lld\n", z);
	return 0;
}