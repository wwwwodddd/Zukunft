#include <bits/stdc++.h>
using namespace std;
struct Point {
	int x, y;
	Point(int x = 0, int y = 0): x(x), y(y) {
	}
	void scan() {
		scanf("%d%d", &x, &y);
	}
	int length() {
		return hypot(x, y);
	}
}a, b, c, p;
int det(Point a, Point b) {
	return a.x * b.y - b.x * a.y;
}
Point operator-(Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}
bool operator<(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int n, z;
int main() {
	a.scan();
	b.scan();
	c.scan();
	if (det(b - a, c - a) < 0) {
		swap(b, c);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		p.scan();
		if (det(b - a, p - a) >= 0 && det(c - b, p - b) >= 0 && det(a - c, p - c) >= 0) {
			z++;
		}
	}
	printf("%.1f\n%d\n", det(b - a, c - a) * .5, z);
	return 0;
}