#include <bits/stdc++.h>
using namespace std;
int t, n, p;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &p);
		if (p <= 2) {
			puts("impossible");
		} else {
			for (int i = 0; i < n / p; i++) {
				printf("a");
				for (int j = 0; j < p - 2; j++) {
					printf("b");
				}
				printf("a");
			}
			printf("\n");
		}
	}
	return 0;
}
