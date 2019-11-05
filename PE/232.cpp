#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double g[220][220];
double G(int x, int y) {
	if (y >= 200) {
		return 1;
	}
	if (x >= 200) {
		return 0;
	}
	if (g[x][y] > 0) {
		return g[x][y];
	}
	for (int i = 1; i < 10; i++) {
		double a = (G(x + 2, y));
		double b = (G(x, y + (1 << i)) + G(x + 2, y + (1 << i)));
		g[x][y] = max(g[x][y], (a * ((1 << i) - 1) + b) / ((1 << i) * 2 - ((1 << i) - 1)));
	}
	return g[x][y];
}
int main() {
	printf("%.8f\n", (G(0, 0) + G(2, 0)) / 2);
	return 0;
}