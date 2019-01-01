#include <bits/stdc++.h>
using namespace std;
long long f[60];
int a[60], c, t, n;
int main() {
	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i <= 50; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		c = 0;
		printf("%d=", n);
		for (int i = 50; i >= 0; i--) {
			if (n >= f[i]) {
				n -= f[a[c++] = i];
			}
		}
		printf("%d", f[a[c - 1]]);
		for (int i = c - 2; i >= 0; i--) {
			printf("+%d", f[a[i]]);
		}
		printf("\n");
	}
}