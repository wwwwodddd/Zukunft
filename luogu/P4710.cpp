#include <bits/stdc++.h>
using namespace std;
double v, th, g = 10;
int main() {
	cin >> v >> th;
	double vx = v * sin(th);
	double vy = v * cos(th);
	double t = vy / g;
	printf("%.3f %.3f\n", t * vx, t * vy / 2);
	return 0;
}