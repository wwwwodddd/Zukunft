#include <bits/stdc++.h>
using namespace std;
int n, x, s, z;
int main() {
	scanf("%d", &n);
	z = -10000;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		s = max(s, 0) + x;
		z = max(z, s);
	}
	printf("%d\n", z);
	return 0;
}