#include <bits/stdc++.h>
using namespace std;
int n, ss = 1, x, y;
vector<int> a[100020];
int l[100020];
int r[100020];
int c[100020];
int z[100020];
void dfs(int x, int y)
{
	l[x] = ss++;
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
	r[x] = ss;
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
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		printf("%d\n", query(l[x]));
		change(l[x], 1);
		change(r[x], -1);
	}
	return 0;
}