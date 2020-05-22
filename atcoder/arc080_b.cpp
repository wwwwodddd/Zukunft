#include <bits/stdc++.h>
using namespace std;
int h, w, n, a[10020], c, x;
int main() {
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		while (x--) {
			a[c++] = i;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d%c", a[i * w + (i & 1 ? w - j - 1: j)], j == w - 1 ? '\n' : ' ');
		}
	}
	return 0;
}