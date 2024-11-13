#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[2000020];
int f[2000020];
int d[2000020];
int t[2000020][26], tt;
int s[2000020], ss;
int b[2000020];
int e[2000020];
int l[2000020];
int h[2000020];
int p[2000020];
int q[2000020], qq;
char c[2000020];
int ins(char *s)
{
	int p = 0;
	for (; *s; s++)
	{
		if (t[p][*s - 'a'] == 0)
		{
			t[p][*s - 'a'] = ++tt;
		}
		p = t[p][*s - 'a'];
	}
	return p;
}
void dfs(int x, int y)
{
	s[x] = 1;
	f[x] = y;
	d[x] = d[y] + 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			s[x] += s[i];
			if (!b[x] || s[b[x]] < s[i])
			{
				b[x] = i;
			}
		}
	}
}
void dfs2(int x, int y)
{
	l[x] = y;
	h[x] = ++ss;
	if (b[x] > 0)
	{
		dfs2(b[x], y);
	}
	for (int i : a[x])
	{
		if (i != b[x] && i != f[x])
		{
			dfs2(i, i);
		}
	}
}
int lca(int x, int y)
{
	for (; l[x] != l[y]; x = f[l[x]])
	{
		if (d[l[x]] < d[l[y]])
		{
			swap(x, y);
		}
	}
	if (d[x] > d[y])
	{
		swap(x, y);
	}
	return x;
}
void change(int x, int y)
{
	assert(x > 0);
	for (int i = x; i <= ss; i += i & -i)
	{
		e[i] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += e[i];
	}
	return re;
}
bool cmp(int x, int y)
{
	return h[x] < h[y];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", c);
		p[i] = ins(c);
	}
	q[qq++] = 0;
	for (int j = 0; j < qq; j++)
	{
		int u = q[j];
		for (int i = 0; i < 26; i++)
		{
			if (t[u][i])
			{
				f[t[u][i]] = u ? t[f[u]][i] : 0;
				a[f[t[u][i]]].push_back(t[u][i]);
				q[qq++] = t[u][i];
			}
			else
			{
				t[u][i] = t[f[u]][i];
			}
		}
	}
	dfs(0, -1);
	dfs2(0, 0);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int o;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%s", c);
			qq = strlen(c);
			int p = 0;
			for (int i = 0; i < qq; i++)
			{
				p = t[p][c[i] - 'a'];
				q[i] = p;
				change(h[q[i]], 1);
			}
			sort(q, q + qq, cmp);
			for (int i = 1; i < qq; i++)
			{
				change(h[lca(q[i - 1], q[i])], -1);
			}
		}
		else
		{
			int x;
			scanf("%d", &x);
			printf("%d\n", query(h[p[x]] + s[p[x]] - 1) - query(h[p[x]] - 1));
		}
	}
	return 0;
}