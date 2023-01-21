#include <bits/stdc++.h>
using namespace std;
struct Point {
	int x, y;
	Point(int x = 0, int y = 0): x(x), y(y) {
	}
	void scan() {
		scanf(" (%d,%d)", &x, &y);
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
bool operator==(Point a, Point b) {
	return a.x == b.x && a.y == b.y;
}
bool inseg(Point a, Point b, Point p) {
	if (b < a) {
		swap(a, b);
	}
	return det(b - a, p - a) == 0 && a < p && p < b;
}
int main() {
	a.scan();
	b.scan();
	c.scan();
	p.scan();
	if (det(b - a, c - a) < 0) {
		swap(b, c);
	}
	if (a == p || b == p || c == p) {
		puts("4");
	} else if (inseg(a, b, p) || inseg(b, c, p) || inseg(c, a, p)) {
		puts("3");
	} else if (det(b - a, p - a) > 0 && det(c - b, p - b) > 0 && det(a - c, p - c) > 0) {
		puts("1");
	} else {
		puts("2");
	}
	return 0;
}