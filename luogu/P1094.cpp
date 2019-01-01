#include <bits/stdc++.h>
using namespace std;
int w, n, a[100020], z;
int main() {
	scanf("%d%d", &w, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = n - 1; i >= z; i--) {
		if (i > z && a[i] + a[z] <= w) {
			z++;
		}
	}
	printf("%d\n", n - z);
	return 0;
}