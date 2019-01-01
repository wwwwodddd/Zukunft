#include <bits/stdc++.h>
using namespace std;
int n, t, z;
int a[200020];
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || a[i + 1] - a[i] > t) {
			z += t;
		} else {
			z += a[i + 1] - a[i];
		}
	}
	printf("%d\n", z);
	return 0;
}