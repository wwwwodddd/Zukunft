#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double a, b, c, ax, ay, bx, by, cx, cy, d, e, f, s, ix, iy, r;
int main() {
	for (;;) {
		scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
		if (ax == 0 && bx == 0 && cx == 0 && ay == 0 && by == 0 && cy == 0) {
			break;
		}
		a = hypot(bx - cx, by - cy);
		b = hypot(cx - ax, cy - ay);
		c = hypot(ax - bx, ay - by);
		ix = (a * ax + b * bx + c * cx) / (a + b + c);
		iy = (a * ay + b * by + c * cy) / (a + b + c);
		d = hypot(ix - ax, iy - ay);
		e = hypot(ix - bx, iy - by);
		f = hypot(ix - cx, iy - cy);
		s = (a + b + c) / 2;
		r = sqrt((s - a) * (s - b) * (s - c) / s);
		printf("%.6f ",  r * (s + d - r - e - f) / (2 * (s - a)));
		printf("%.6f ",  r * (s + e - r - f - d) / (2 * (s - b)));
		printf("%.6f\n", r * (s + f - r - d - e) / (2 * (s - c)));
	}
}