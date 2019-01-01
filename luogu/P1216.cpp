#include <bits/stdc++.h>
using namespace std;
int n;
int a[1020][1020];
int f[1020][1020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
		}
	}
	printf("%d\n", f[0][0]);
	return 0;
}