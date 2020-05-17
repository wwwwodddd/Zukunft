#include <bits/stdc++.h>
using namespace std;
int n, ss, x;
vector<int> a[100020];
int p[100020];
int o[100020];
int l[100020];
int r[100020];
int c[100020];
int z[100020];
void dfs(int x)
{
	l[x] = ss;
	for (int i: a[x])
	{
		dfs(i);
	}
	r[x] = ++ss;
}
void change(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		o[i] = i;
	}
	sort(o + 1, o + 1 + n, [](int x,int y){return p[x]>p[y];});
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &x);
		a[x].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		z[o[i]] = query(r[o[i]]) - query(l[o[i]]);
		change(r[o[i]], 1);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}