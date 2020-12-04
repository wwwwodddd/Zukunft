#include <bits/stdc++.h>
using namespace std;
int n, a[500020], s;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s ^= a[i];
	}
	if (s == 0) {
		printf("lose\n");
	} else {
		for (int i = 0; i < n; i++) {
			if (a[i] > (s ^ a[i])) {
				printf("%d %d\n", a[i] - (s ^ a[i]), i + 1);
				a[i] = s ^ a[i];
				for (int j = 0; j < n; j++) {
					printf("%d%c", a[j], j == n - 1 ? '\n' :' ');
				}
				break;
			}
		}
	}
}