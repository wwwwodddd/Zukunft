#include <bits/stdc++.h>
using namespace std;
int n, k, a[10000];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	k--;
	if (k < n) {
		printf("%d\n", a[k]);
	} else {
		printf("NO RESULT\n");
	}
	return 0;
}
