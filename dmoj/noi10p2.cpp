#include <bits/stdc++.h>
using namespace std;
int n, k, x, y;
long long s[1000020];
pair<long long, int> f[20][1000020];
struct N
{
	int l, r, s, p;
	long long w;
	bool operator<(const N &a) const
	{
		return w < a.w;
	}
} u, v;
priority_queue<N> q;
int A(int x, int y)
{
	int l = 31 - __builtin_clz(y - x + 1);
	return max(f[l][x], f[l][y - (1 << l) + 1]).second;
}
int main()
{
	scanf("%d%d%d%d", &n, &k, &x, &y);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
		f[0][i] = make_pair(s[i], i);
	}
	for (int i = 0; 1 << i < n; i++)
	{
		for (int j = 1; j + (1 << i) <= n; j++)
		{
			f[i + 1][j] = max(f[i][j], f[i][j + (1 << i)]);
		}
	}
	for (int i = 0; i + x <= n; i++)
	{
		u.l = i + x;
		u.r = min(i + y, n);
		u.s = i;
		u.p = A(u.l, u.r);
		u.w = s[u.p] - s[u.s];
		q.push(u);
	}
	long long z = 0;
	for (int i = 0; i < k; i++)
	{
		u = q.top();
		q.pop();
		z += u.w;
		v = u;
		if (u.p > u.l)
		{
			v.r = u.p - 1;
			v.p = A(v.l, v.r);
			v.w = s[v.p] - s[v.s];
			q.push(v);
		}
		v = u;
		if (u.p < u.r)
		{
			v.l = u.p + 1;
			v.p = A(v.l, v.r);
			v.w = s[v.p] - s[v.s];
			q.push(v);
		}
	}
	printf("%lld\n", z);
	return 0;
}