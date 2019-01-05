#include <bits/stdc++.h>
using namespace std;
struct Point {
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {

	}
	void scan() {
		scanf("%lf%lf", &x, &y);
	}
	void print() {
		printf("%.2f %.2f\n", x, y);
	}
	double length() {
		return hypot(x, y);
	}
}p[100020], s[10020];
double det(Point a, Point b) {
	return a.x * b.y - b.x * a.y;
}
Point operator-(Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}
bool operator<(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int n, ss;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		p[i].scan();
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		while (ss >= 2 && det(s[ss - 1] - s[ss - 2], p[i] - s[ss - 1]) >= 0) {
			ss--;
		}
		s[ss++] = p[i];
	}
	int t = ss;
	for (int i = n - 2; i >= 0; i--) {
		while (ss > t && det(s[ss - 1] - s[ss - 2], p[i] - s[ss - 1]) >= 0) {
			ss--;
		}
		s[ss++] = p[i];
	}
	ss--;
	double ans = 0;
	for (int i = 0; i < ss; i++) {
		ans += (s[i + 1] - s[i]).length();
	}
	printf("%.2f\n", ans);
	return 0;
}