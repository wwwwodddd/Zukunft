#include <bits/stdc++.h>
using namespace std;
struct P
{
	int x, y, z, f;
	void scan()
	{
		scanf("%d%d%d", &x, &y, &z);
	}
}a[100020];
bool cmpx(const P&a, const P&b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	if (a.y != b.y)
	{
		return a.y < b.y;
	}
	return a.z < b.z;
}
bool cmpy(const P&a, const P&b)
{
	if (a.y != b.y)
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}
int n, m;
int c[200020];
void change(int x, int y) {
	for (int i = x; i <= m; i += i & -i) {
		c[i] += y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
void cdq(int l, int r)
{
	if (l + 1 == r)
	{
		return;
	}
	int mid = (l + r) / 2;
	cdq(l, mid);
	cdq(mid, r);
	sort(a + l, a + r, cmpy);
	for (int i = l; i < r; i++)
	{
		if (a[i].x < mid)
		{
			change(a[i].z, 1);
		}
		else
		{
			a[i].f += query(a[i].z);
		}
	}
	for (int i = l; i < r; i++)
	{
		if (a[i].x < mid)
		{
			change(a[i].z, -1);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		a[i].scan();
	}
	sort(a, a + n, cmpx);
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i].x == a[i + 1].x && a[i].y == a[i + 1].y && a[i].z == a[i + 1].z)
		{
			a[i].f = a[i + 1].f + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i].x = i;
	}
	cdq(0, n);
	for (int i = 0; i < n; i++)
	{
		c[a[i].f]++;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", c[i]);
	}
	return 0;
}