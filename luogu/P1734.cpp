#include <bits/stdc++.h>
using namespace std;
int s, f[1020];
int main() {
	scanf("%d", &s);
	for (int i = 1; i <= s; i++) {
		int v = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				v += j;
			}
		}
		for (int j = s; j >= i; j--) {
			f[j] = max(f[j], f[j - i] + v);
		}
	}
	printf("%d\n", f[s]);
	return 0;
}
