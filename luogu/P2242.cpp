#include <bits/stdc++.h>
using namespace std;
int a[15020];
int n, m, s;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1] - a[i];
	}
	sort(a, a + n - 1);
	for (int i = 0; i < n - m; i++) {
		s += a[i];
	}
	printf("%d\n", s + m);
	return 0;
}