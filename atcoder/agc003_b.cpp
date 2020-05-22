#include <bits/stdc++.h>
using namespace std;
int n, a[1000020];
long long z, s;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > 0) {
			s += a[i];
		} else {
			z += s / 2;
			s = a[i];
		}
	}
	printf("%lld\n", z + s / 2);
	return 0;
}