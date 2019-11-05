#include <bits/stdc++.h>
using namespace std;
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {

	}

	void scan() {
		scanf("%lf%lf", &x, &y);
	}

	void print() {
		printf("(%.9f, %.9f)\n", x, y);
	}

	double length() {
		return hypot(x, y);
	}

	double angle() {
		return atan2(y, x);
	}


};

double Pi = acos(-1.0), eps = 1e-12;

Point unit(double angle) {
	return Point(cos(angle), sin(angle));
}

Point operator+(const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y);
}

Point operator-(const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

Point operator*(const Point &a, double f) {
	return Point(a.x * f, a.y * f);
}

Point operator/(const Point &a, double f) {
	return Point(a.x / f, a.y / f);
}

double cross(const Point &a, const Point &b) {
	return a.x * b.y - b.x * a.y;
}

double dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

double sgn(double x) {
	return x < -eps ? -1 : x > eps; 
}

Point intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
	assert(cross(b - a, d - c));
	double abc = cross(b - a, c - a);
	double bad = cross(a - b, d - b);
	return (d * abc + c * bad) / (abc + bad);
}



void test() {
//	intersect(Point(-1, 0), Point(1, 0), Point(0, 2), Point(3, 1)).print();
}


double days = 0;
bool debug = false;
bool calculate(double angle) {
	days = 0;
	Point start = Point(-50, 0);
	Point direction = unit(angle);
	Point end = Point(50, 0);
	if (debug) {
		start.print();
	}
	for (int i = 0; i < 6; i++) {
		double ref1 = 10.0 / (10 - i);
		double ref2 = 10.0 / (9 - i);
		if (i == 5) {
			ref2 = 10.0;
		}
		Point surface1 = Point((-25 + 10 * i) * sqrt(2), 0);
		Point surface2 = Point(0, (25 - 10 * i) * sqrt(2));
		Point intersection = intersect(start, start + direction, surface1, surface2);
		double angle1 = direction.angle() + Pi / 4;
		assert(sin(angle1) * ref1 / ref2 < 1);
		double angle2 = asin(sin(angle1) * ref1 / ref2);

		days += (intersection - start).length() / (10.0 - i);
		if (debug) {
			printf("%.6f\n", (intersection - start).length());
			printf("%.6f %.6f\n", angle1, angle2);
			printf("%.6f %.6f\n", sin(angle1), sin(angle2));
			printf("%.6f %.6f\n", ref1 * sin(angle1), ref2 * sin(angle2));
			start.print();
			intersection.print();
			direction.print();
			printf("\n");
		}
		direction = unit(angle2 - Pi / 4);
		start = intersection;
	}

	days += (end - start).length() / (10.0);
	if (debug) {
		printf("%.6f\n", (end - start).length());
		start.print();
		end.print();
		direction.print();
		printf("%.6f\n", cross(direction, end - start));
	}
	return cross(direction, end - start) < 0;
}

int main() {
	test();
	double L = 0;
	double R = Pi / 4;

	// for (int _ = 0; _ < 100; _++) {
	// 	double M = (L + R) / 2;
	// 	if (calculate(M)) {
	// 		R = M;
	// 	} else {
	// 		L = M;
	// 	}
	// 	printf("%.10f\n", days);
	// }
	for (int _ = 0; _ < 100; _++) {
		double ML = (2 * L + R) / 3;
		double MR = (L + 2 * R) / 3;
		calculate(ML);
		double daysL = days;
		calculate(MR);
		double daysR = days;
		if (daysL < daysR) {
			R = MR;
		} else {
			L = ML;
		}
		printf("%.6f %.6f %.6f %.6f\n", ML, MR, daysL, daysR);
	}
	debug = true;
	calculate((L + R) / 2);
	printf("%.12f\n", (L + R) / 2);
	printf("%.10f\n", days);
	return 0;
}