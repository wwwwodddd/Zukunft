#include <bits/stdc++.h>
using namespace std;
int n;
int A, B;
int main() {
	scanf("%d", &n);
	int key = -1;
	bool A0 = false, B0 = false;
	for (int i = 0; 1 << i < n; i++) {
		int cnt1 = 0, cnt0 = 0;
		int ans1 = 0, ans0 = 0;
		for (int j = 1; j <= n; j++) {
			if (j >> i & 1) {
				cnt1++;
			} else {
				cnt0++;
			}
		}
		printf("Q %d", cnt1);
		for (int j = 1; j <= n; j++) {
			if (j >> i & 1) {
				printf(" %d", j);
			} else {

			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &ans1);

		printf("Q %d", cnt0);
		for (int j = 1; j <= n; j++) {
			if (j >> i & 1) {

			} else {
				printf(" %d", j);
			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &ans0);
		if (ans1 == 0 && ans0 == cnt0) {
			A0 = true;
			key = i;
		}
		if (ans0 == 0 && ans1 == cnt1) {
			B0 = true;
			key = i;
		}
		assert(key >= 0);
		if (A0) {
			B |= 1 << key;
		} else {
			A |= 1 << key;
		}
		for (int k = 0; 1 << k < n; k++) {
			if (k != key) {
				int cnt1 = 0, cnt0 = 0;
				int ans1 = 0, ans0 = 0;
				for (int j = 1; j <= n; j++) {
					if ((j >> key & 1) || (j >> k & 1)) {
						cnt1++;
					}
					if ((~j >> key & 1) || (~j >> k & 1)) {
						cnt0++;
					}
				}
				printf("Q %d", cnt1);
				for (int j = 1; j <= n; j++) {
					if ((j >> key & 1) || (j >> k & 1)) {
						printf(" %d", j);
					}
				}
				printf("\n");
				fflush(stdout);
				scanf("%d", &ans1);
				printf("Q %d", cnt0);
				for (int j = 1; j <= n; j++) {
					if ((~j >> key & 1) || (~j >> k & 1)) {
						printf(" %d", j);
					}
				}
				printf("\n");
				fflush(stdout);
				scanf("%d", &ans0);
				if (ans0 == 0) {
					A |= 1 << k;
				} else if (ans1 == cnt1) {
					B |= 1 << k;
				}
			}
		}
		printf("A %d %d\n", A, B);
	}
	return 0;
}