#include <bits/stdc++.h>
using namespace std;
struct P
{
	int x, y, z, i;
}a[100020];
bool cmpy(const P&a, const P&b)
{
	return a.y < b.y;
}
int n, m, x;
int p[100020];
int c[100020];
long long z[100020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
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
	int cnt = 0;
	for (int i = l; i < r; i++)
	{
		if (a[i].x < mid)
		{
			cnt++;
			change(a[i].z, 1);
		}
		else
		{
			z[a[i].i] += cnt - query(a[i].z);
		}
	}
	for (int i = l; i < r; i++)
	{
		if (a[i].x < mid)
		{
			change(a[i].z, -1);
		}
	}
	for (int i = r - 1; i >= l; i--)
	{
		if (a[i].x < mid)
		{
			change(a[i].z, 1);
		}
		else
		{
			z[a[i].i] += query(a[i].z);
		}
	}
	for (int i = r - 1; i >= l; i--)
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
		scanf("%d", &x);
		p[x] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		a[i].x = n - i - 1;
		a[i].y = p[x];
		a[i].z = x;
		a[i].i = i;
		p[x] = -1;
	}
	for (int i = 1, j = m; i <= n; i++)
	{
		if (p[i] != -1)
		{
			a[j].x = n - j - 1;
			a[j].y = p[i];
			a[j].z = i;
			a[j].i = j;
			j++;
		}
	}
	reverse(a, a + n);
	cdq(0, n);
	for (int i = n - 1; i >= 0; i--)
	{
		z[i] += z[i + 1];
	}
	for (int i = 0; i < m; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}