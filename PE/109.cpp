#include <iostream>
#include <cstdio>
using namespace std;
int ans = 0;
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25};
int limit = 100;
int main() {
	for (int i = 0; i < 21; i++) {
		if (2 * a[i] < limit) {
			ans++;
		}
	}

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if (a[i] + 2 * a[j] < limit) {
				ans++;
			}
		}
	} // S D

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if (2 * a[i] + 2 * a[j] < limit) {
				ans++;
			}
		}
	} // D D

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 21; j++) {
			if (3 * a[i] + 2 * a[j] < limit) {
				ans++;
			}
		}
	} // T D

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 21; k++) {
				if (a[i] + a[j] + 2 * a[k] < limit) {
					ans++;
				}
			}
		}
	} // S S D

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 21; k++) {
				if (3 * a[i] + 3 * a[j] + 2 * a[k] < limit) {
					ans++;
				}
			}
		}
	} // T T D

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < 21; k++) {
				if (a[i] + 3 * a[j] + 2 * a[k] < limit) {
					ans++;
				}
			}
		}
	} // S T D

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				if (a[i] + 2 * a[j] + 2 * a[k] < limit) {
					ans++;
				}
			}
		}
	} // S D D

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				if (3 * a[i] + 2 * a[j] + 2 * a[k] < limit) {
					ans++;
				}
			}
		}
	} // T D D

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 21; k++) {
				if (2 * a[i] + 2 * a[j] + 2 * a[k] < limit) {
					ans++;
				}
			}
		}
	} // D D D

	printf("%d\n", ans);
	return 0;
}