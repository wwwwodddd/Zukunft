//DNF
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
	double x, y;
	Point() {
	}
	Point(double _x, double _y) :
		x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator*(double d) const {
		return Point(x * d, y * d);
	}
	double det(const Point&p) const {
		return x * p.y - y * p.x;
	}

	void read() {
		scanf("%lf%lf", &x, &y);
	}
	double distTo(const Point&p) const {
		return hypot(x - p.x, y - p.y);
	}
};

const double EPS = 1e-8;

const int MAX_N_CIRCLES = 100000 + 10;
struct Segment
{
	double l, r;
	int id;
	Segment(double _l, double _r, int _id):
		l(_l), r(_r), id(_id) {
	}
	Segment() {
	}
};
struct Circle
{
	Point c;
	double r;
	int id;
	int withX(double x)
	{
		if (fabs(c.x - x) <= r)
			return 0;
		return c.x < x ? -1 : 1;
	}

	Segment cutX(double x) {
		double dx = c.x - x;
		double dy = sqrt(r * r - dx * dx);
		return Segment(c.y - dy, c.y + dy, id);
	}

	void read(int _id) {
		id = _id;
		c.read();
		scanf("%lf", &r);
	}
};

vector<Point> isCC(Circle a, Circle b) {
	//can't be covered
	double d = a.c.distTo(b.c);
	if (d >= a.r + b.r)
		return vector<Point> ();
	double p = (a.r * a.r - d * d - b.r * b.r) / (2 * d);
	Point at = a.c + (b.c - a.c) * (p / d);
	double h = sqrt(a.r * a.r - p * p);
	Point dir = (b.c - a.c) * (h / d);
	vector<Point> ret;
	ret.push_back(at - dir);
	ret.push_back(at + dir);
	return ret;
}
int nCircles;
Circle circles[MAX_N_CIRCLES];

int main() {
	scanf("%d", &nCircles);
	double Lx = 1e100, Rx = -1e100;
	for (int i = 0; i < nCircles; ++i) {
		Circle&c = circles[i];
		c.read(i);
		Lx = min(Lx, c.c.x - c.r);
		Rx = max(Rx, c.c.x + c.r);
	}

	while (Rx - Lx > 1e-10) {
		double Mx = (Lx + Rx) / 2;
		bool has[3] = { };
		for (int i = 0; i < nCircles; ++i) {
			has[circles[i].withX(Mx) + 1] = true;
		}
		if (has[0] && has[2]) {
			puts("NO");
			return 0;
		}

		static Segment segments[MAX_N_CIRCLES];
		if (has[0]) {
			Rx = Mx;
			continue;
		}
		if (has[2]) {
			Lx = Mx;
			continue;
		}
		for (int i = 0; i < nCircles; ++i) {
			segments[i] = circles[i].cutX(Mx);
		}

		Segment minR = segments[0], maxL = segments[0];
		for (int i = 0; i < nCircles; ++i) {
			Segment cur = segments[i];
			if (cur.r < minR.r)
				minR = cur;
			if (cur.l > maxL.l)
				maxL = cur;
		}

		if (maxL.l + EPS <= minR.r) {
			puts("YES");
			return 0;
		}

		vector<Point> is = isCC(circles[maxL.id], circles[minR.id]);
		if (is.empty()) {
			puts("NO");
			return 0;
		}
		Point it = is.front();
		if (it.x >= Mx)
			Lx = Mx;
		else
			Rx = Mx;
	}
	puts("NO");
}