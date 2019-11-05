#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[20];
int b[20];
int n = 11;
bool check() {
	for (int i = 0; i < n - 1; i++) {
		if (i < n - 2) {
			if (a[i] == i || a[n - 1] == i) {
				return false;
			}
			int idx = -1;
			for (int j = i; j < n; j++) {
				if (a[j] == i) {
					idx = j;
				}
			}
			reverse(a + idx, a + n);
			reverse(a + i, a + n);
		} else {
			if (a[i] == i) {
				return false;
			}
			reverse(a + i, a + n);
		}
	}
	return true;
}
int cnt = 0;
int main() {
	for (int i = 0; i < n; i++) {
		b[i] = i;
	}
	do {
		for (int i = 0; i < n; i++) {
			a[i] = b[i];
		}
		if (check()) {
			cnt++;
			if (cnt == 2011) {
				for (int i = 0; i < n; i++) {
					printf("%c", b[i] + 'A');
				}
				printf("\n");
			}
		}
	} while (next_permutation(b, b + n));
	return 0;
}