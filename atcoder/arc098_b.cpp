#include <bits/stdc++.h>
using namespace std;
int n, a[200020], b, r;
long long z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		while (r < n && (b ^ a[r]) == (b + a[r])) {
			b += a[r];
			r++;
		}
		z += r - i;
		b -= a[i];
	}
	printf("%lld\n", z);
	return 0;
}