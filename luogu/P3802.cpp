#include <bits/stdc++.h>
using namespace std;
double a[7], z, s;
int main() {
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
		s += a[i];
	}
	if (s < 7) {
		z = 0;
	} else {
		z = 1;
		for (int i = 0; i < 7; i++) {
			z *= a[i] / (s - i) * (i + 1);
		}
		z *= s - 6;
	}
	printf("%.3f\n", z);
	return 0;
}