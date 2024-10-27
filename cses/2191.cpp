#include <bits/stdc++.h>
using namespace std;
struct Point
{
	long long x, y;
	Point(long long x = 0, long long y = 0) : x(x), y(y)
	{
	}
	void scan()
	{
		scanf("%lld%lld", &x, &y);
	}
} p[100020];
long long det(Point a, Point b)
{
	return a.x * b.y - b.x * a.y;
}
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i].scan();
	}
	p[n] = p[0];
	long long z = 0;
	for (int i = 0; i < n; i++)
	{
		z += det(p[i + 1], p[i]);
	}
	printf("%lld\n", abs(z));
	return 0;
}