#include <bits/stdc++.h>
using namespace std;
int lm[1048577];
int rm[1048577];
int mx[1048577];
int sa[1048577];
void merge(int x, int l, int r, int mid)
{
	if (lm[x * 2] == mid - l + 1)
	{
		lm[x] = mid - l + 1 + lm[x * 2 + 1];
	}
	else
	{
		lm[x] = lm[x * 2];
	}
	if (rm[x * 2 + 1] == r - mid)
	{
		rm[x] = r - mid + rm[x * 2];
	}
	else
	{
		rm[x] = rm[x * 2 + 1];
	}
	mx[x] = max(rm[x * 2] + lm[x * 2 + 1], max(mx[x * 2], mx[x * 2 + 1]));
}
void build(int x, int l, int r)
{
	if (l == r)
	{
		lm[x] = rm[x] = mx[x] = 1;
		sa[x] = -1;
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	merge(x, l, r, mid);
}
void sam(int x, int l, int r, int v)
{
	if (v == 0)
	{
		lm[x] = rm[x] = mx[x] = r - l + 1;
	}
	else
	{
		lm[x] = rm[x] = mx[x] = 0;
	}
	sa[x] = v;
}
void push(int x, int l, int r, int mid)
{
	if (sa[x] != -1)
	{
		sam(x * 2, l, mid, sa[x]);
		sam(x * 2 + 1, mid + 1, r, sa[x]);
		sa[x] = -1;
	}
}
void change(int x, int l, int r, int L, int R, int v)
{
	if (r < L || R < l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		sam(x, l, r, v);
		return;
	}
	int mid = (l + r) / 2;
	push(x, l, r, mid);
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid + 1, r, L, R, v);
	merge(x, l, r, mid);
}
int query(int x, int l, int r, int s)
{
	assert(mx[x] >= s);
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) / 2;
	push(x, l, r, mid);
	if (mx[x * 2] >= s)
	{
		return query(x * 2, l, mid, s);
	}
	else if (rm[x * 2] + lm[x * 2 + 1] >= s)
	{
		return mid - rm[x * 2] + 1;
	}
	else
	{
		return query(x * 2 + 1, mid + 1, r, s);
	}
}
int main()
{
	int n, m, z = 0;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		char o;
		int x, y;
		scanf(" %c", &o);
		if (o == 'A')
		{
			scanf("%d", &x);
			if (x > mx[1])
			{
				z++;
			}
			else
			{
				int p = query(1, 1, n, x);
				change(1, 1, n, p, p + x - 1, 1);
			}
		}
		else
		{
			scanf("%d%d", &x, &y);
			change(1, 1, n, x, y, 0);
		}
	}
	printf("%d\n", z);
	return 0;
}