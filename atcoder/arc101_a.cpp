#include <bits/stdc++.h>
using namespace std;
int n, k, a[100020], z = 1e9;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i + k - 1 < n; i++) {
		z = min(z, a[i + k - 1] - a[i] + min(abs(a[i]), abs(a[i + k - 1])));
	}
	printf("%d\n", z);
	return 0;
}