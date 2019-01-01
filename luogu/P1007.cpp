#include <bits/stdc++.h>
using namespace std;
int l, n, x, y, z;
int main() {
	scanf("%d%d", &l, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		y = max(y, min(x, l + 1 - x));
		z = max(z, max(x, l + 1 - x));
	}
	printf("%d %d\n", y, z);
	return 0;
}