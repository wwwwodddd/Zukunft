#include <bits/stdc++.h>
using namespace std;
int z[10001];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 2, t = i; j <= t; j++) {
			while (t % j == 0) {
				t /= j;
				z[j]++;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		if (z[i]) {
			printf("%d %d\n", i, z[i]);
		}
	}
	return 0;
}