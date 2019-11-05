#include <bits/stdc++.h>
using namespace std;
int n = 400 / 2;
double pi = acos(-1.0);
double check(double a, double x, double b) {
	return (sin(b) - sin(x)) * sin(x) - (cos(a) - cos(x)) * cos(x);
}

double calc(double first, double second) {
	if (check(first, second, pi / 2) < 0) {
		return pi;
	}
	double L = second;
	double R = pi / 2;
	for (int _ = 0; _ < 100; _++) {
		double M = (L + R) / 2;
		if (check(first, second, M) < 0) {
			L = M;
		} else {
			R = M;
		}
	}
	return (L + R) / 2;
}
double result[1000];
bool ok(double M) {
	double first, second, third;
	first = 0;
	second = M;
	result[0] = 0;
	for (int i = 0; i < n; i++) {
		result[i + 1] = second;
		third = calc(first, second);
		if (third > pi / 2) {
			return false;
		}
		first = second;
		second = third;
	}
	result[n + 1] = second;
	return true;
}
int main() {
	double L = 0;
	double R = pi / 2;
	for (int _ = 0; _ < 100; _++) {
		double M = (L + R) / 2;
		if (ok(M)) {
			L = M;
		} else {
			R = M;
		}
	}
	double ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += cos(result[i]) * (sin(result[i + 1]) - sin(result[i]));
	}
	ans *= 4;
	printf("%.12f\n", ans);
	for (int i = 0; i <= n; i++) {
		printf("%d %.6f %.6f\n", i, result[i], pi / 2 - result[i]);
	}
}