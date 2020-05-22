#include <bits/stdc++.h>
using namespace std;
int n, x, l = -1;
long long z = -1;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x <= l) {
			z += x;
		} else if (x == l + 1) {
			z++;
		} else {
			printf("-1\n");
			return 0;
		}
		l = x;
	}
	printf("%lld\n", z);
	return 0;
}