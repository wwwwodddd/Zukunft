#include <stdio.h>
#include <iostream>
using namespace std;
int n, z;
int f[1000020];
int S(int x) {
	return (x - 1) % 9 + 1;
}
int main() {
	n = 1000000;
	for (int i = 2; i < n; i++) {
		if (i % 1000 == 0) {
			printf("%d\n", i);
		}
		f[i] = S(i);
		for (int j = 2; j * j <= n; j++) {
			if (i % j == 0) {
				f[i] = max(f[i], f[j] + f[i / j]);
			}
		}
		z += f[i];
	}
	printf("%d\n", z);
	return 0;
}
