#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
typedef long long ll;
ll a[520][520];
int n, m, c, z, v[520];
pair<int, int> b[520];
int pw(ll x, int y)
{
	int re = 1;
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
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i].first);
		b[i].second = i;
		v[i] = -1;
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[j] != -1)
			{
				int u = a[b[i].second][j];
				for (int k = 0; k < m; k++)
				{
					a[b[i].second][k] = (a[b[i].second][k] - u * a[v[j]][k]) % p;
					if (a[b[i].second][k] < 0)
					{
						a[b[i].second][k] += p;
					}
				}
			}
			else if (a[b[i].second][j])
			{
				v[j] = b[i].second;
				int u = pw(a[b[i].second][j], p - 2);
				for (int k = 0; k < m; k++)
				{
					a[b[i].second][k] = a[b[i].second][k] * u % p;
				}
				c++;
				z += b[i].first;
				break;
			}
		}
	}
	printf("%d %d\n", c, z);
	return 0;
}