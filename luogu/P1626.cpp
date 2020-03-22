#include <bits/stdc++.h>
using namespace std;
int a[100020];
int n, m, s;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1] - a[i];
	}
	sort(a, a + n - 1);
	for (int i = 0; i < m; i++) {
		s += a[i];
	}
	printf("%d\n", s);
	return 0;
}