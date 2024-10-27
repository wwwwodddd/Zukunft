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
	void print()
	{
		printf("%lld %lld\n", x, y);
	}
} p[200020], s[200020];
long long det(Point a, Point b)
{
	return a.x * b.y - b.x * a.y;
}
Point operator-(Point a, Point b)
{
	return Point(a.x - b.x, a.y - b.y);
}
bool operator<(Point a, Point b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int n, ss;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i].scan();
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++)
	{
		while (ss >= 2 && det(s[ss - 1] - s[ss - 2], p[i] - s[ss - 1]) > 0)
		{
			ss--;
		}
		s[ss++] = p[i];
	}
	int t = ss;
	for (int i = n - 2; i >= 0; i--)
	{
		while (ss > t && det(s[ss - 1] - s[ss - 2], p[i] - s[ss - 1]) > 0)
		{
			ss--;
		}
		s[ss++] = p[i];
	}
	ss--;
	printf("%d\n", ss);
	for (int i = 0; i < ss; i++)
	{
		s[i].print();
	}
	return 0;
}