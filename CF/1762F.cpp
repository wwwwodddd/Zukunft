#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[500020];
int s[500020];
int mn[500020];
int f[500020];
long long z = 0;
int ask(int x, int l, int r, int L, int R)
{
	if (r < L || R < l)
	{
		return 1e9;
	}
	if (L <= l && r <= R)
	{
		return mn[x];
	}
	int m = (l + r) / 2;
	return min(ask(x * 2, l, m, L, R), ask(x * 2 + 1, m + 1, r, L, R));
}
int query(int x, int l, int r, int L, int R)
{
	if (r < L || R < l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		return s[x];
	}
	int m = (l + r) / 2;
	return query(x * 2, l, m, L, R) + query(x * 2 + 1, m + 1, r, L, R);
}
vector<int> d;
void change(int x, int l, int r, int p, int v)
{
	d.push_back(x);
	if (l == r)
	{
		s[x]++;
		mn[x] = v;
		return;
	}
	int m = (l + r) / 2;
	if (p <= m)
	{
		change(x * 2, l, m, p, v);
	}
	else
	{
		change(x * 2 + 1, m + 1, r, p, v);
	}
	s[x] = s[x * 2] + s[x * 2 + 1];
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
void work()
{
	for (int i : d)
	{
		s[i] = 0;
		mn[i] = 1e9;
	}
	d.clear();
	for (int i = n; i--;)
	{
		int j = ask(1, 1, 100000, a[i] + 1, a[i] + k);
		if (j > n)
		{
			f[i] = 0;
		}
		else
		{
			f[i] = f[j] + query(1, 1, 100000, a[i] + 1, a[j]);
		}
		change(1, 1, 100000, a[i], i);
		z += f[i];
	}
}
int main()
{
	memset(mn, 0x3f, sizeof mn);
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		map<int, int> g;
		z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			z += ++g[a[i]];
		}
		work();
		reverse(a, a + n);
		work();
		printf("%lld\n", z);
	}
	return 0;
}