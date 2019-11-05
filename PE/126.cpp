#include <bits/stdc++.h>
using namespace std;

long long calc(int a, int b, int c, int d) {
	long long s = 0;
	s += (a * b + b * c + c * a) * 2;
	s += (a + b + c) * 4 * (d - 1);
	s += 8 * (d - 2) * (d - 1) / 2;
	return s;
}

int c[40000];

int main() {
	int n = 20000;
	for (int i = 1;; i++) {
		if (6 * i * i >= n) {
			break;
		}
		for (int j = i;; j++) {
			if (2 * i * i + 4 * i * j >= n) {
				break;
			}
			for (int k = j;; k++) {
				if (2 * (i * j + j * k + k * i) >= n) {
					break;
				}
				for (int d = 1;; d++) {
					long long tmp = calc(i, j, k, d);
					if (tmp >= n) {
						break;
					}
//					printf("%lld\n", tmp);
					c[tmp]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == 1000) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}