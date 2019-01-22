#include <bits/stdc++.h>
using namespace std;
int a[5020];
int b[5020];
int main() {
	int n;
	scanf("%d", &n);
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5010; j++) {
			a[j] *= 2;
		}
		for (int j = 0; j < 5010; j++) {
			a[j + 1] += a[j] / 1000000000;
			a[j] %= 1000000000;
		}
	}
	int l = 5010;
	while (a[l] == 0) {
		l--;
	}
	a[0]--;
	printf("%d", a[l]);
	for (int j = l - 1; j >= 0; j--) {
		printf("%09d", a[j]);
	}
	printf("\n");
	return 0;
}