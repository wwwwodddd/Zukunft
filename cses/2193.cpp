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
Point operator-(Point a, Point b)
{
	return Point(a.x - b.x, a.y - b.y);
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
	long long s = 0, c = 0;
	for (int i = 0; i < n; i++)
	{
		s += det(p[i + 1], p[i]);
		auto u = p[i + 1] - p[i];
		c += gcd(u.x, u.y);
	}
	printf("%lld %lld\n", (abs(s) - c) / 2 + 1, c);
	return 0;
}