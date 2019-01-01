#include <bits/stdc++.h>
using namespace std;
int n, a[10000], z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				z++;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}
