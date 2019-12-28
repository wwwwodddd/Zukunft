#include <stdio.h>
#include <iostream>
using namespace std;
double f[1020], l, r;
int n;
int main() {
	while(scanf("%d", &n), n) {
		scanf("%lf%lf", &l, &r);
		for (int i = 1; i <= n; i++) {
			f[i] = 1e30;
			for (int j = 0; j < i; j++) {
				f[i] = min(f[i], f[j] + f[i - j - 1] + f[j] * ((1 / (1 - l - r) - 1) * r / (r + l))  + f[i - j - 1] * ((1 / (1 - l - r) - 1) * l / (r + l))  + 1 / (1 - l - r));
			}
		}
		printf("%.2f\n", f[n]);
	}
}
