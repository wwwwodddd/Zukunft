#include <bits/stdc++.h>
using namespace std;
int n, z, x, f[200020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		z = max(z, f[x] = f[x - 1] + 1);
	}
	printf("%d\n", n - z);
	return 0;
}