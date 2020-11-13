#include <bits/stdc++.h>
using namespace std;
int n, a[100020], c;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] >= c) {
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}