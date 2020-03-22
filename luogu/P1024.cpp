#include <bits/stdc++.h>
using namespace std;
double A, B, C, D;
double F(double x) {
	return (((A * x + B) * x + C) * x + D);
}
int main() {
	cin >> A >> B >> C >> D;
	for (int i = -110; i < 110; i++) {
		if (F(i) == 0) {
			printf("%.2f ", (double)i);
		} else if (F(i) * F(i + 1) < 0) {
			double L = i;
			double R = i + 1;
			for (int _ = 0; _ < 60; _++) {
				double M = (L + R) / 2;
				if (F(M) * F(L) > 0) {
					L = M;
				} else {
					R = M;
				}
			}
			printf("%.2f ", L);
		}
	}		
}