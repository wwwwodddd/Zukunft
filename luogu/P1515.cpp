#include <bits/stdc++.h>
using namespace std;
int a[99] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000}, n, A, B;
long long f[99];
int main() {
	scanf("%d%d%d", &A, &B, &n);
	n += 14;
	for (int i = 14; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	f[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A <= a[i] - a[j] && a[i] - a[j] <= B) {
				f[i] += f[j];
			}
		}
	}
	printf("%lld\n", f[n - 1]);
	return 0;
}