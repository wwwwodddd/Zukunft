#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	double l = 0, z = 100, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &x);
		x /= 100;
		z = max(z, z * l / x);
		l = x;
	}
	printf("%.2f\n", z);
	return 0;
}
