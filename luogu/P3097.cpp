#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[200020][4];
void pull(int x, int l, int r)
{
	for (int i = 0; i < 4; i++)
	{
		f[x][i] = max(f[2 * x][i & 2] + f[2 * x + 1][i & 1], max(f[2 * x][i & 2] + f[2 * x + 1][i | 2], f[2 * x][i | 1] + f[2 * x + 1][i & 1]));
	}
}
void build(int x, int l, int r)
{
	if (l == r)
	{
		scanf("%d", &f[x][3]);
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	pull(x, l, r);
}
void change(int x, int l, int r, int p, int v)
{
	if (l == r)
	{
		f[x][3] = v;
		return;
	}
	int mid = (l + r) / 2;
	if (p > mid)
	{
		change(x * 2 + 1, mid + 1, r, p, v);
	}
	else
	{
		change(x * 2, l, mid, p, v);
	}
	pull(x, l, r);
}
int main()
{
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	long long z = 0;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		change(1, 1, n, x, y);
		z += max(max(f[1][0], f[1][1]), max(f[1][2], f[1][3]));
	}
	printf("%lld\n", z);
	return 0;
}