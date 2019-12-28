#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int n, k, a[10020];
int main() {
	while(true) {
		scanf("%d %d", &n ,&k);
		memset(a, 0, sizeof a);
		if (n == -1 && k == -1) {
			break;
		}
		for (int i = 0; i <= n; i++) {
			scanf("%d", a + i);
		}
		if (k == 0) {
			printf("0\n");
			continue;
		}
		for (int i = n; i >= k; i--) {
			a[i - k] -= a[i];
			a[i] = 0;
		}
		while (k > 0 && a[k - 1] == 0) {
			k--;
		}
		for (int i = 0; i < k; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}