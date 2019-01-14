#include <bits/stdc++.h>
using namespace std;
int C(int x) {
	int r = 0;
	while (x % 5 == 0) {
		x /= 5;
		r++;
	}
	return r;
}
int main() {
	int L = 0;
	int R = 1000000 + 1;
	while (L < R - 1) {
		int M = (L + R) / 2;
		printf("Q %d\n", M);
		fflush(stdout);
		int r;
		scanf("%d", &r);
		if (r) {
			L = M;
		} else {
			R = M;
		}
	}
	int zero = L;
	for (int i = 1; i <= 100020; i++) {
		zero -= C(i);
		if (zero <= 0) {
			printf("A %d\n", i);
			return 0;
		}
	}
}