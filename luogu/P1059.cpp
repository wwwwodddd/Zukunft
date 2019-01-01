#include <bits/stdc++.h>
using namespace std;
int n, a[1000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}
