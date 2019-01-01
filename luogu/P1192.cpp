#include <bits/stdc++.h>
using namespace std;
int f[100200];
int n, k, p = 100003;
int main() {
	scanf("%d%d", &n, &k);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k && j <= i; j++) {
			f[i] += f[i - j];
			f[i] %= p;
		}
	}
	printf("%d\n", f[n]);
	return 0;
}