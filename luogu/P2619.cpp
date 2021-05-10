#include <bits/stdc++.h>
using namespace std;
int n, m, need, M, w;
struct E
{
	int x, y, z, w;
	void scan()
	{
		scanf("%d%d%d%d", &x, &y, &z, &w);
		w ^= 1;
	}
} a[100020];
int f[100020];
bool cmp(const E &a, const E &b)
{
	return a.z - M * a.w < b.z - M * b.w || (a.z - M * a.w == b.z - M * b.w && a.w < b.w);
}
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int calc()
{
	int _ = 0;
	w = 0;
	sort(a, a + m, cmp);
	for (int i = 0; i < n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		if (F(a[i].x) != F(a[i].y))
		{
			w += a[i].z - M * a[i].w;
			_ += a[i].w;
			f[F(a[i].x)] = F(a[i].y);
		}
	}
	return _;
}
int main()
{
	scanf("%d %d %d", &n, &m, &need);
	for (int i = 0; i < m; i++)
	{
		a[i].scan();
	}
	int L = -101, R = 101;
	while (L < R - 1)
	{
		M = (L + R) >> 1;
		if (calc() > need)
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	M = L;
	calc();
	printf("%d\n", w + need * M);
	return 0;
}