#include <bits/stdc++.h>
using namespace std;
int n, m;
int lm[200020];
int rm[200020];
int mx[200020];
int sa[200020];
void pull(int x, int l, int r)
{
	int mid = (l + r) / 2;
	lm[x] = (lm[2 * x] == (mid - l + 1) ? (mid - l + 1) + lm[2 * x + 1] : lm[2 * x]);
	rm[x] = (rm[2 * x + 1] == (r - mid) ? (r - mid) + rm[2 * x] : rm[2 * x + 1]);
	mx[x] = max(rm[2 * x] + lm[2 * x + 1], max(mx[2 * x], mx[2 * x + 1]));
}
void build(int x, int l, int r)
{
	sa[x] = -1;
	if (l == r)
	{
		lm[x] = 1;
		rm[x] = 1;
		mx[x] = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	pull(x, l, r);
}
void sam(int x, int l, int r, int v)
{
	if (v == 0)
	{
		lm[x] = r - l + 1;
		rm[x] = r - l + 1;
		mx[x] = r - l + 1;
		sa[x] = 0;
	}
	else
	{
		lm[x] = 0;
		rm[x] = 0;
		mx[x] = 0;
		sa[x] = 1;
	}
}
void push(int x, int l, int r)
{
	int mid = (l + r) / 2;
	if (sa[x] == 0)
	{
		sam(x * 2, l, mid, 0);
		sam(x * 2 + 1, mid + 1, r, 0);
		sa[x] = -1;
	}
	else if (sa[x] == 1)
	{
		sam(x * 2, l, mid, 1);
		sam(x * 2 + 1, mid + 1, r, 1);
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
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid + 1, r, L, R, v);
	pull(x, l, r);
}
int ask(int x, int l, int r, int s)
{
	int mid = (l + r) / 2;
	push(x, l, r);
	if (mx[2 * x] >= s)
	{
		return ask(2 * x, l, mid, s);
	}
	else if (rm[2 * x] + lm[2 * x + 1] >= s)
	{
		return mid - rm[2 * x] + 1;
	}
	else if (mx[2 * x + 1] >= s)
	{
		return ask(2 * x + 1, mid + 1, r, s);
	}
	else
	{
		assert(false);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d", &y);
			if (mx[1] >= y)
			{
				x = ask(1, 1, n, y);
				printf("%d\n", x);
				change(1, 1, n, x, x + y - 1, 1);
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			scanf("%d%d", &x, &y);
			change(1, 1, n, x, x + y - 1, 0);
		}
	}
	return 0;
}