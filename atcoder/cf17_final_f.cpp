#include <bits/stdc++.h>
using namespace std;
int k = 38, n = k * (k - 1) + 1;
int main() {
	printf("%d %d\n", n, k);
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < k; j++) {
			printf("%d ", i * (k - 1) + j);
		}
		printf("%d\n", n);
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - 1; j++) {
			for (int l = 0; l < k - 1; l++) {
				printf("%d ", l * (k - 1) + (j + i * l) % (k - 1) + 1);
			}
			printf("%d\n", n - k + i + 1);
		}
	}
	return 0;
}