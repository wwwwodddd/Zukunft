#include <bits/stdc++.h>
using namespace std;
int n;
struct P
{
	int x, y;
} a[400020];
long long z = 1e18;
bool cmpx(const P &a, const P &b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmpy(const P &a, const P &b)
{
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}
void divide_and_conquer(int l, int r)
{
	if (r - l <= 1)
	{
		return;
	}
	int m = (l + r) / 2;
	long long amx = a[m].x;
	divide_and_conquer(l, m);
	divide_and_conquer(m, r);
	inplace_merge(a + l, a + m, a + r, cmpy);
	vector<P> b;
	for (int i = l; i < r; i++)
	{
		if ((long long)(a[i].x - amx) * (a[i].x - amx) <= z)
		{
			b.push_back(a[i]);
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = i + 1; j < b.size() && (long long)(b[i].y - b[j].y) * (b[i].y - b[j].y) <= z; j++)
		{
			z = min(z, (long long)(b[i].x - b[j].x) * (b[i].x - b[j].x) + (long long)(b[i].y - b[j].y) * (b[i].y - b[j].y));
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a, a + n, cmpx);
	divide_and_conquer(0, n);
	printf("%lld\n", z);
	return 0;
}
