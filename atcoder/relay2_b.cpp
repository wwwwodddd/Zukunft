#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &x, &y);
		while (true) {
			if (x > y) {
				swap(x, y);
			}
			if (x == y || n == 1) {
				break;
			}
			y = (y + n - 2) / n;
		}
		printf("%d\n", x);
	}
	return 0;
}