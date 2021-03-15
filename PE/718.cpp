#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int u, v, w;
long long d[24137569];
int main()
{
	int p = 6;
	u = v = w = 1;
	for (int i = 0; i < p; i++)
	{
		u *= 17;
		v *= 19;
		w *= 23;
	}
	memset(d, 0x3f, sizeof d);
	priority_queue<pair<int, int> > q;
	d[(u + v + w) % u] = (u + v + w) / u;
	q.push(make_pair(-d[(u + v + w) % u], (u + v + w) % u));
	while (q.size())
	{
		int x = q.top().second;
		q.pop();
		long long t, y;
		t = x + u * d[x] + v;
		y = t % u;
		if (d[y] > t / u)
		{
			d[y] = t / u;
			q.push(make_pair(-d[y], y));
		}
		t = x + u * d[x] + w;
		y = t % u;
		if (d[y] > t / u)
		{
			d[y] = t / u;
			q.push(make_pair(-d[y], y));
		}
	}
	long long z = 0;
	for (int i = 0; i < u; i++)
	{
		z = (z + d[i] % mod * i + d[i] % mod * (d[i] % mod - 1) / 2 % mod * u) % mod;
	}
	printf("%lld\n", z);
	return 0;
}