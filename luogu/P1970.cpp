#include <bits/stdc++.h>
using namespace std;
int n, l, x, f = 1, g = 1;
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		if (x > l) {
			f = g + 1;
		} else if (x < l) {
			g = f + 1;
		}
		l = x;
	}
	printf("%d\n", max(f, g));
	return 0;
}