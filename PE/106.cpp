#include <iostream>
#include <cstdio>
using namespace std;
int ans;
int main() {
	int n = 12;
	for (int i = 0; i < 1 << n; i++) {
		for (int j = i;; --j &= i) {
			if (i != j && j != 0) {
				int B = i ^ j;
				int C = j;
				if (B > C) {
					continue;
				}
				if (__builtin_popcount(B) == __builtin_popcount(C)) {
					int flag = false;
					while (B != 0 && C != 0) {
						int lb = B & -B;
						B -= lb;
						int lc = C & -C;
						C -= lc;
						if (lb > lc) {
							flag = true;
						}
					}
					if (flag) {
						ans += 1;
					}
				}
			}
			if (j == 0) {
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}