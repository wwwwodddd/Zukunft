#include <bits/stdc++.h>
using namespace std;
int a[1020];
int b[1020];
int main() {
	int n;
	scanf("%d", &n);
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 1000; j++) {
			a[j] *= i;
		}
		for (int j = 0; j < 1000; j++) {
			a[j + 1] += a[j] / 10;
			a[j] %= 10;
		}
		for (int j = 0; j < 1000; j++) {
			b[j] += a[j];
		}
		for (int j = 0; j < 1000; j++) {
			b[j + 1] += b[j] / 10;
			b[j] %= 10;
		}
	}
	int l = 1000;
	while (b[l] == 0) {
		l--;
	}
	for (int j = l; j >= 0; j--) {
		printf("%d", b[j]);
	}
	printf("\n");
	return 0;
}
