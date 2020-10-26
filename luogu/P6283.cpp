#include <bits/stdc++.h>
using namespace std;
struct P
{
	int x, y, r;
} a[100020];
bool cmp1(const P&a, const P&b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmp2(const P&a, const P&b)
{
	return a.y > b.y || (a.y == b.y && a.x > b.x);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a, a + n, cmp1);
	for (int i = 0; i < n; i++)
	{
		a[i].r = i;
	}
	int mx = 0, z = 0;
	sort(a, a + n, cmp2);
	for (int i = 0; i < n; i++)
	{
		mx = max(mx, a[i].r);
		if (mx == i)
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}