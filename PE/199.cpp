#include <bits/stdc++.h>
using namespace std;
double F(double k1, double k2, double k3, int x) {
	if (x == 0) {
		return 0;
	}
	double k4 = k1 + k2 + k3 + 2 * sqrt(k1 * k2 + k2 * k3 + k3 * k1);
	return 1 / k4 / k4 + F(k1, k2, k4, x - 1) + F(k1, k4, k3, x - 1) + F(k4, k2, k3, x - 1);
}
int main() {
	double k0 = -1;
	double k1 = 1 + 2 / sqrt(3);
	int n = 10;
	double ans = 3 / k1 / k1 + F(k1, k1, k1, n) + F(k0, k1, k1, n) * 3;
	printf("%.8f\n", 1 - ans);
	return 0;
}