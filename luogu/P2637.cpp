#include <bits/stdc++.h>
using namespace std;
int n, m, a[1020], x, z;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + m);
	reverse(a, a + m);
	for (int i = 1; i <= min(n, m); i++) {
		if (z < i * a[i - 1]) {
			z = i * a[i - 1];
			x = a[i - 1];
		}
	}
	printf("%d %d\n", x, z);
	return 0;
}