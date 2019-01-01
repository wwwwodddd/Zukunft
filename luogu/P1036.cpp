#include <bits/stdc++.h>
using namespace std;
int n, k, a[30], z;
bool Prime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 1 << n; i++) {
		int s = 0, c = 0;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				c++;
				s += a[j];
			}
		}
		if (c == k && Prime(s)) {
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}