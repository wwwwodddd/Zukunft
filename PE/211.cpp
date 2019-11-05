#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int v[64000020];
long long f[64000020];
int n;
long long ans;
int main() {
//	scanf("%d", &n);
	n = 64000000;
	for (int i = 2; i < n; i++) {
		if (v[i] == 0) {
			for (int j = i; j < n; j += i) {
				v[j] = i;
			}
		}
	}
	f[1] = 1;
	for (int i = 2; i < n; i++) {
		if (v[i] == v[i / v[i]]) {
			f[i] = f[i / v[i]] + (f[i / v[i]] - f[i / v[i] / v[i]]) * v[i] * v[i];
		}
		else {
			f[i] = f[i / v[i]] * ((long long)v[i] * v[i] + 1);
		}
	}
	for (int i = 1; i < n; i++) {
		long long t = max((long long)sqrt(f[i]) - 10, 0LL);
		while (t * t < f[i]) {
			t++;
		}
		if (t * t == f[i]) {
			printf("%d %lld\n", i, f[i]);
			ans += i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}