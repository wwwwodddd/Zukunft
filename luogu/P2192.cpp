#include <bits/stdc++.h>
using namespace std;
int n, x, c[10];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		c[x]++;
	}
	if (c[0] == 0) {
		printf("-1\n");
	} else if (c[5] < 9) {
		printf("0\n");
	} else {
		for (int i = 0; i < c[5] / 9 * 9; i++) {
			printf("5");
		}
		for (int i = 0; i < c[0]; i++) {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
