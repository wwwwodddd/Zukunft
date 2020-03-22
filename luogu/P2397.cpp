#include <bits/stdc++.h>
using namespace std;
int n, x, z, c;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == z) {
			c++;
		} else {
			if (c > 0) {
				c--;
			} else {
				z = x;
				c = 1;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}