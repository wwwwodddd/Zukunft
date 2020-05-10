#include <bits/stdc++.h>
using namespace std;
int n;
double r, x, y, xa, ya, xb, yb;
double gao() {
	if (xa * xa + ya * ya <= r * r && xb * xb + yb * yb <= r * r) {
		return hypot(xa - xb, ya - yb);
	} else if (xa * xa + ya * ya > r * r && xb * xb + yb * yb > r * r) {
		// 3 situations.
		double S = abs(xa * yb - xb * ya);
		double h = S / hypot(xa - xb, ya - yb);
		if (h < r) {
			double A = xa * xa + ya * ya + xb * xb + yb * yb - 2 * xa * xb - 2 * ya * yb;
			double B = -2 * (xa * xa + ya * ya) + 2 * xa * xb + 2 * ya * yb;
			double C = xa * xa + ya * ya - r * r;
			double delta = B * B - 4 * A * C;
			double x1 = (-B + sqrt(delta)) / (2 * A);
			double x2 = (-B - sqrt(delta)) / (2 * A);
			if (0 <= x1 && x1 <= 1 && 0 <= x2 && x2 <= 1) {
				return (x1 - x2) * hypot(xa - xb, ya - yb);
			} else {
				return 0;
			}
		} else {
			return 0;
		}
	} else {
		if (xa * xa + ya * ya > r * r) {
			swap(xa, xb);
			swap(ya, yb);
		}
		// a in, b out
		double A = xa * xa + ya * ya + xb * xb + yb * yb - 2 * xa * xb - 2 * ya * yb;
		double B = -2 * (xa * xa + ya * ya) + 2 * xa * xb + 2 * ya * yb;
		double C = xa * xa + ya * ya - r * r;
		double delta = B * B - 4 * A * C;
		double x = (-B + sqrt(delta)) / (2 * A);
		return x * hypot(xa - xb, ya - yb);
	}
}
int main() {
	scanf("%d%lf%lf%lf", &n, &r, &x, &y);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
		xa -= x;
		xb -= x;
		ya -= y;
		yb -= y;
		printf("%.12f\n", gao());
	}
	return 0;
}