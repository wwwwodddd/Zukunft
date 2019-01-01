#include <bits/stdc++.h>
using namespace std;
int n, z, c, l, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == l + 1) {
			c++;
		} else {
			c = 1;
		}
		z = max(z, c);
		l = x;
	}
	printf("%d\n", z);
	return 0;
}
