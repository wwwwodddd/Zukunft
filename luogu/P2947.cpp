#include <bits/stdc++.h>
using namespace std;
int n;
int h[100020];
int f[100020];
int main() {
	scanf("%d", &n);
	h[0] = 1 << 30;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = n - 1; i > 0; i--) {
		int j;
		for (j = i + 1; h[i] >= h[j]; j = f[j]) {

		}
		f[i] = j;
		
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", f[i]);
	}
	return 0;
}