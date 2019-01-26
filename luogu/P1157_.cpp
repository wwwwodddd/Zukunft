#include <bits/stdc++.h>
using namespace std;
int n, r, a[30];
int main() {
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		a[i] = 1;
	}
	for (int i = 0; i < r; i++) {
		a[i] = 0;
	}
	do {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				printf("%3d", i + 1);
			}
		}
		printf("\n");
	} while (next_permutation(a, a + n));
}