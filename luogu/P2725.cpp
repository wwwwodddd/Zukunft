#include <bits/stdc++.h>
using namespace std;
int f[2000020];
int k, n, x;
int main() {
	cin >> k >> n;
	for (int i = 1; i < 2000010; i++) {
		f[i] = k + 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = x; j < 2000010; j++) {
			f[j] = min(f[j], f[j - x] + 1);
		}
	}
	for (int i = 0; i < 2000010; i++) {
		if (f[i] > k) {
			printf("%d\n", i - 1);
			break;
		}
	}
}