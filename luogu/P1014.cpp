#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 1;; i++) {
		if (n > i) {
			n -= i;
		} else {
			if (i & 1) {
				printf("%d/%d\n", i + 1 - n, n);
			} else {
				printf("%d/%d\n", n, i + 1 - n);
			}
			break;
		}
	}
	return 0;
}