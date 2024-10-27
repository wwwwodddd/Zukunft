#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
int mx[800020];
void build(int x, int l, int r)
{
	if (l == r)
	{
		mx[x] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}
int query(int x, int l, int r, int v)
{
	if (l == r)
	{
		if (mx[x] >= v)
		{
			mx[x] -= v;
			return l;
		}
		else
		{
			return 0;
		}
	}
	int mid = (l + r) / 2;
	int p = 0;
	if (mx[x * 2] >= v)
	{
		p = query(x * 2, l, mid, v);
	}
	else if (mx[x * 2 + 1] >= v)
	{
		p = query(x * 2 + 1, mid + 1, r, v);
	}
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
	return p;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d ", query(1, 1, n, x));
	}
	return 0;
}