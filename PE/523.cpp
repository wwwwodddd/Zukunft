#include <iostream>
#include <cmath>
using namespace std;
double f[1000][1000];
int n = 30;
int main() {
	for (int i = 0; i < n; i++) {
		f[i][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			f[i][j] = 1;
			for (int k = 1; k <= j; k++) {
				f[i][j] += f[k][k - 1];
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		printf("%.6f ", f[i][j]);
	// 	}
	// 	printf("\n");
	// }

	double s = 0;
	for (int i = 0; i < n; i++) {
		double t = (double)((1 << i) - 1) / (i + 1);
		s += t;
	}
	printf("%.6f\n", s);
	return 0;
}
