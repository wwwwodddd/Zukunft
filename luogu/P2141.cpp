#include <bits/stdc++.h>
using namespace std;
int n, a[1020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int z = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] + a[j] == a[k]) {
					z++;
					goto end;
				}
			}
		}
		end:;
	}
	printf("%d\n", z);
	return 0;
}
