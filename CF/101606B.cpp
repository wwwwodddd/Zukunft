#include <bits/stdc++.h>
using namespace std;
int n;
struct P {
	double x, y;
	P(double x = 0, double y = 0): x(x), y(y) {

	}
	void read() {
		cin >> x >> y;
	}
	double len() {
		return hypot(x, y);
	}
}p[120];

P operator+(const P&a, const P&b) {
	return P(a.x + b.x, a.y + b.y);
}
P operator-(const P&a, const P&b) {
	return P(a.x - b.x, a.y - b.y);
}

double xm(P a, P b) {
	return a.x * b.y - a.y * b.x;
}
double dist(P a, P b, P c) {
	double area = xm(b - a, c - a);
	double dist = (a - b).len();
	return area / dist;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		p[i].read();
	}

	double ans = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			double tmp = 0, tmq = 0;
			for (int k = 0; k < n; k++) {
				double dd = dist(p[i], p[j], p[k]);
				tmp = max(tmp, dd);
				tmq = min(tmq, dd);
			}
			ans = min(ans, tmp - tmq);
		}
	}
	printf("%.12f\n", ans);
	return 0;
}