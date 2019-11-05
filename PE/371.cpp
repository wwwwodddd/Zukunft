#include <iostream>
#include <cstdio>
using namespace std;
double f[2][510];
int main() {
	for (int i = 499; i >= 0; i--) {
		f[1][i] = (2. * (499 - i) / 1000. * f[1][i + 1] + (i + 1) / 1000. * 0 + 1) / (1 - (i + 1) / 1000.);
		f[0][i] = (2. * (499 - i) / 1000. * f[0][i + 1] + 1 / 1000. * f[1][i] + i / 1000. * 0 + 1) / (1 - (i + 1) / 1000.);
	}
	printf("%.8f\n", f[0][0]);
	return 0;
}