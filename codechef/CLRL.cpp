#include <bits/stdc++.h>
using namespace std;
int t, n, r;
int low, high;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &r);
		low = high = -1;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (x > r) {
				if (high == -1) {
					high = x;
				} else {
					if (high < x) {
						ok = false;
					}
					high = x;
				}
			} else {
				if (low == -1) {
					low = x;
				} else {
					if (low > x) {
						ok = false;
					}
					low = x;
				}
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
